/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:25:00 by vifonne           #+#    #+#             */
/*   Updated: 2021/01/02 06:17:18 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "corewar.h"
#include "process.h"
#include "func_op.h"
#include "op.h"


int			lld(t_env *env, t_process *cur_process, uint8_t *bytes)
{
	int			ret;
	t_decode	decode;
	uint32_t	value;
	int			reg;

	fill_decode(env, cur_process, &decode, 2);
	ret = decode_args(&decode, bytes + 2, *(bytes + 1), REG_DIR) + 2;
	if ((decode.tab[0].type == IND_CODE || decode.tab[0].type == DIR_CODE)
			&& decode.tab[1].type == REG_CODE)
	{
		store_multitype(&value, decode, decode.tab[0], 1);
		reg = (int)decode.tab[1].value;
		cur_process->reg[reg - 1] = value;
		cur_process->carry = (value == 0);
	}
	return (ret);
}
