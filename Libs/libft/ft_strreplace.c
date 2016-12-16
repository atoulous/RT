/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:12:34 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/16 16:15:57 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char old, char new, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == old)
			str[i] = new;
	return (str);
}
