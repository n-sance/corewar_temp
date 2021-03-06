/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:04:23 by vifonne           #+#    #+#             */
/*   Updated: 2019/02/22 07:05:26 by nsance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "corewar.h"
#include "func_op.h"
#include "op.h"

int			ft_xor(t_env *env, t_process *cur_process, uint8_t *bytes)
{
	int			ret;
	t_decode	decode;
	int			idx;
	uint32_t	args[2];
	uint32_t	tmp;

	fill_decode(env, cur_process, &decode, 3);
	ret = decode_args(&decode, bytes + 2, *(bytes + 1), 0) + 2;
	if (decode.tab[0].type != BAD_REG
			&& decode.tab[1].type != BAD_REG
			&& decode.tab[2].type == REG_CODE)
	{
		idx = -1;
		while (++idx < 2)
			store_multitype(&args[idx], decode, decode.tab[idx], 0);
		tmp = args[0] ^ args[1];
		cur_process->reg[(int)decode.tab[2].value - 1] = tmp;
		cur_process->carry = (tmp == 0);
	}
	return (ret);
}
