/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:42:59 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/31 00:57:20 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

#include <stddef.h>

enum e_instruction
{
	SWAP_A,
	SWAP_B,
	SWAP_AB,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_AB,
	REVERSE_ROTATE_A,
	REVERSE_ROTATE_B,
	REVERSE_ROTATE_AB,
};

int	get_function(void);

#endif
