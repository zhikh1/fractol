/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:36:07 by nomargen          #+#    #+#             */
/*   Updated: 2021/10/25 15:01:22 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *string )
{
	int	len;

	len = 0;
	while (string[len])
		len++;
	return (len);
}
