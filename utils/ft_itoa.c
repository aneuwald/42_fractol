/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:35:26 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 00:23:46 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static size_t   ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

static int		nbr_digits(int n)
{
	int counter;

	counter = 0;
	while (n > 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

static char		*handle_exception(int n)
{
	char *str;

	if (n == 0)
	{
		if (!(str = malloc(2 * sizeof(char))))
			return (NULL);
		ft_strlcpy(str, "0", 2);
	}
	else
	{
		if (!(str = malloc(12 * sizeof(char))))
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		isneg;
	int		len;

	if (n == 0 || n == -2147483648)
		return (handle_exception(n));
	isneg = 0;
	len = nbr_digits(n >= 0 ? n : -n) + 1;
	if (n < 0)
	{
		len++;
		isneg = 1;
		n = -n;
	}
	if (!(str = malloc(len * sizeof(char))))
		return (NULL);
	str[--len] = '\0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (isneg)
		str[0] = '-';
	return (str);
}