/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:49:35 by rciera            #+#    #+#             */
/*   Updated: 2020/11/24 21:12:24 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	correct_char(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '0' + base - 1);
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'A' + base - 11));
}

int			ft_atoi_base(char *str, int base)
{
	int sign;
	int res;

	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (correct_char(*str, base))
	{
		res = res * base;
		res += (*str >= '0' && *str <= '9') ? *str - '0' : *str - 'A' + 10;
		str++;
	}
	return (res * sign);
}
