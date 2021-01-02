/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:15:06 by nsance          #+#    #+#             */
/*   Updated: 2019/02/22 04:01:48 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "visual.h"
#include "corewar.h"
#include "process.h"
#include "func_op.h"
#include "op.h"

int			st(t_env *env, t_process *cur_process, uint8_t *bytes)
{
	int			ret;
	t_decode	decode;
	uint32_t	value;

	fill_decode(env, cur_process, &decode, 2);
	ret = decode_args(&decode, bytes + 2, *(bytes + 1), REG_DIR) + 2;
	if ((decode.tab[1].type == REG_CODE || decode.tab[1].type == IND_CODE)
			&& decode.tab[0].type == REG_CODE)
	{
		store_multitype(&value, decode, decode.tab[0], 0);
		if (decode.tab[1].type == REG_CODE)
			cur_process->reg[(int)decode.tab[1].value - 1] = value;
		else
		{
			write_in_arena(env, (uint8_t *)&value, 4
					, cur_process->pc + (int)decode.tab[1].value % IDX_MOD);
		}
	}
	return (ret);
}
