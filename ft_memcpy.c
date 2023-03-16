/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:04:49 by kkalika           #+#    #+#             */
/*   Updated: 2023/01/17 20:07:55 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sauce;
	size_t	i;

	if (!src || !dst || n <= 0)
		return (0);
	dest = (char *) dst;
	sauce = (char *) src;
	i = 0;
	while (n != i)
	{
		dest[i] = sauce[i];
		i++;
	}
	return (dst);
}
