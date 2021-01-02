/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 23:39:23 by vifonne           #+#    #+#             */
/*   Updated: 2021/01/02 06:16:14 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "corewar.h"
#include "func_op.h"
#include "op.h"

int			sub(t_env *env, t_process *cur_process, uint8_t *bytes)
{
	int			ret;
	t_decode	decode;
	int			idx;
	int			value;

	fill_decode(env, cur_process, &decode, 3);
	ret = decode_args(&decode, bytes + 2, *(bytes + 1), 0) + 2;
	idx = 0;
	while (idx < 3)
	{
		if (decode.tab[idx].type != REG_CODE)
			return (ret);
		idx++;
	}
	value = (int)cur_process->reg[(int)decode.tab[0].value - 1];
	value -= (int)cur_process->reg[(int)decode.tab[1].value - 1];
	cur_process->reg[(int)decode.tab[2].value - 1] = (uint32_t)value;
	cur_process->carry = (value == 0);
	return (ret);
}