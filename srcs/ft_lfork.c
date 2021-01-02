/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 05:18:00 by nsance          #+#    #+#             */
/*   Updated: 2019/02/22 04:11:50 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "corewar.h"
#include "func_op.h"
#include "op.h"

int			ft_lfork(t_env *env, t_process *cur_process, unsigned char *bytes)
{
	int			ret;
	t_decode	decode;
	t_list		*node;
	t_process	*process;

	fill_decode(env, cur_process, &decode, 1);
	ret = decode_args(&decode, bytes + 1, DIR_CODE << 6, SHORT_DIR) + 1;
	node = ft_lstnew(cur_process, sizeof(t_process));
	if (node == NULL)
		return (-1);
	process = (t_process *)node->content;
	process->queued_op = 0;
	increase_pc(process, (int)decode.tab[0].value);
	ft_lstadd(&env->process_lst, node);
	return (ret);
}
