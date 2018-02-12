/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 09:39:11 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 22:02:46 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"
#include "ft_string.h"
#include "ft_printf.h"

static char			*zero_case(char *ascii, int alen, t_token token)
{
	int		total;
	char	*res;

	total = (token.width > alen) ? token.width : alen;
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	while (total >= 0)
	{
		if (alen >= 0)
			res[total--] = ascii[alen--];
		else
			res[total--] = '0';
	}
	return (res);
}

static char			*normal_case(char *ascii, int alen, t_token token)
{
	int		total;
	char	*res;

	total = (token.precision > alen) ? token.precision : alen;
	if (!(res = (char *)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	while (total >= 0)
	{
		if (alen >= 0)
			res[total--] = ascii[alen--];
		else
			res[total--] = '0';
	}
	return (res);
}

static char			*apply_options(
						uintmax_t n,
						char *ascii,
						int alen,
						t_token token)
{
	char	*res;

	if (token.precision == 0 && n == 0)
		res = ft_strdup("");
	else if (token.precision == 1
		&& !ft_strchr(token.flags, '-')
		&& ft_strchr(token.flags, '0'))
		res = zero_case(ascii, alen, token);
	else
		res = normal_case(ascii, alen, token);
	free(ascii);
	return (res);
}

static uintmax_t	convert(va_list *ap, t_length length, char spe)
{
	uintmax_t n;

	n = va_arg(*ap, uintmax_t);
	if (length == l || spe == 'U')
		n = (unsigned long)n;
	else if (length == hh)
		n = (unsigned char)n;
	else if (length == h)
		n = (unsigned short int)n;
	else if (length == ll)
		n = (unsigned long long int)n;
	else if (length == j)
		n = (uintmax_t)n;
	else if (length == z)
		n = (size_t)n;
	else if (length == None)
		n = (unsigned int)n;
	return (n);
}

int					ft_printuint_fd(const int fd, t_token token, va_list *ap)
{
	uintmax_t	n;
	int			len;
	int			cpt;
	char		*tmp;

	n = convert(ap, token.length, token.specifier);
	if (!(tmp = ft_utoa_base(n, "0123456789")))
		return (0);
	if (!(tmp = apply_options(n, tmp, ft_strlen(tmp), token)))
		return (0);
	len = ft_strlen(tmp);
	cpt = (token.width > len) ? token.width - len + len : len;
	if (!ft_strchr(token.flags, '-'))
	{
		while (token.width-- > len)
			write(fd, " ", 1);
	}
	write(fd, tmp, len);
	free(tmp);
	while (token.width-- > len)
		write(fd, " ", 1);
	return (cpt);
}
