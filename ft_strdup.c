/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:06:32 by kkalika           #+#    #+#             */
/*   Updated: 2023/01/17 20:07:55 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s1);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, i + 1);
	return (str);
}
