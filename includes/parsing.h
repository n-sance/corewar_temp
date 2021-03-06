/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:57:40 by vifonne           #+#    #+#             */
/*   Updated: 2019/02/23 05:43:40 by nsance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H
# define BUFF_SIZ 4096

# include "champion.h"
# include "process.h"
# include "corewar.h"

int	read_file(const char *filename, t_champ *champ);

#endif
