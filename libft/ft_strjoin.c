/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:13:16 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/12/29 01:28:41 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	hold1;
	size_t	hold2;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	hold1 = ft_strlen(s1);
	hold2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (hold1 + hold2 + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		new[i++] = s2[j];
	new[i] = '\0';
	return (new);
}
