/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:48:17 by nsance          #+#    #+#             */
/*   Updated: 2019/02/20 04:50:25 by nsance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fix_pc_offset(int *offset)
{
	while (*offset < 0)
		*offset += MEM_SIZE;
	if (*offset >= MEM_SIZE)
		*offset %= MEM_SIZE;
}

void	increase_pc(t_process *process, int value)
{
	process->pc += value;
	fix_pc_offset(&process->pc);
}
