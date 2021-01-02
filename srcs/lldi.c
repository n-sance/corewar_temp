/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 02:58:20 by vifonne           #+#    #+#             */
/*   Updated: 2021/01/02 06:17:07 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "corewar.h"
#include "process.h"
#include "func_op.h"
#include "op.h"

int			lldi(t_env *env, t_process *cur_process, uint8_t *bytes)
{
	int				ret;
	t_decode		decode;
	uint32_t		args[2];
	int				addr;
	uint32_t		value;

	fill_decode(env, cur_process, &decode, 3);
	ret = decode_args(&decode, bytes + 2, *(bytes + 1), SHORT_DIR) + 2;
	if ((decode.tab[1].type == DIR_CODE || decode.tab[1].type == REG_CODE)
			&& decode.tab[2].type == REG_CODE
			&& decode.tab[0].type != BAD_REG)
	{
		store_multitype(&args[0], decode, decode.tab[0], 0);
		store_multitype(&args[1], decode, decode.tab[1], 0);
		addr = cur_process->pc + (int)args[0] + (int)args[1];
		fill_buff_from_arena(env, (uint8_t *)&value, 4, addr);
		swap_bytes((uint8_t *)&value, 4);
		cur_process->reg[(int)decode.tab[2].value - 1] = (uint64_t)value;
	}
	return (ret);
}
