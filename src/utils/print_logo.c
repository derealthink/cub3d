/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_logo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:53:27 by aielo             #+#    #+#             */
/*   Updated: 2026/01/26 16:28:14 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_infos(void)
{
	printf("\n");
	printf("             _    ____  _____  \n");
	printf("            | |  |___ \\|  __ \\ \n");
	printf("   ___ _   _| |__  __) | |  | |\n");
	printf("  / __| | | | '_ \\|__ <| |  | |\n");
	printf(" | (__| |_| | |_) |__) | |__| |\n");
	printf("  \\___|\\__,_|_.__/____/|_____/ \n");
	printf("\n");
	printf("\tW: move forward\t");
	printf("\tS: move backward\n");
	printf("\tA: move left\t");
	printf("\tD: move right\n");
	printf("\t<: rotate left\t");
	printf("\t>: rotate right\n");
	printf("\n");
}
