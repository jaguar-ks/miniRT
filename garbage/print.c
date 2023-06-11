/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 02:20:03 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 03:08:18 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	printf_tab(t_rt *rt)
{
	printf("/*   ABIENT LIGHT   */\n");
	printf("-brightness:\n");
	printf("   -%f\n", rt->al->brightness);
	printf("-RGB:\n");
	printf("   -R: %d\n", rt->al->clr.r);
	printf("   -G: %d\n", rt->al->clr.g);
	printf("   -B: %d\n", rt->al->clr.b);
	printf("*   CAMERA   */\n");
	printf("-fov:\n");
	printf(" -%d\n", rt->cam->fov);
	printf("-cordination:\n");
	printf("   -x: %0.f\n", rt->cam->crd.x);
	printf("   -y: %0.f\n", rt->cam->crd.y);
	printf("   -z: %0.f\n", rt->cam->crd.z);
	printf("-vector:\n");
	printf("   -x: %f\n", rt->cam->nrm.x);
	printf("   -y: %f\n", rt->cam->nrm.y);
	printf("   -z: %f\n", rt->cam->nrm.z);
	printf("/*     LIGHT   */\n");
	printf("-RGB:\n");
	printf("   -R: %d\n", rt->lt->clr.r);
	printf("   -G: %d\n", rt->lt->clr.g);
	printf("   -B: %d\n", rt->lt->clr.b);
	printf("-cordination:\n");
	printf("   -x: %0.f\n", rt->lt->crd.x);
	printf("   -y: %0.f\n", rt->lt->crd.y);
	printf("   -z: %0.f\n", rt->lt->crd.z);
	printf("-Brightness: %f\n", rt->lt->bright);
}

/ char	*extract_elem(char **str, const char *elementPrefix, int h_m_elements)
// {
// 	int		count;
// 	char	**extract_el;
// 	char	*ptr;
// 	size_t	extract_sz;
// 	char	*extract_str;
// 	int		i;

// 	extract_el = malloc((h_m_elements + 1) * sizeof(char *));
// 	if (extract_el == NULL)
// 	{
// 		ft_printf("Error: Allocation problem from extract_elem\n", 2);
// 		return (NULL);
// 	}
// 	count = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		ptr = trim(str[i]);
// 		if (!ft_strncmp(ptr, elementPrefix, ft_strlen(elementPrefix)))
// 		{
// 			extract_el[count] = ft_strdup(str[i]);
// 			count++;
// 		}
// 		free(ptr);
// 		i++;
// 	}
// 	extract_el[count] = NULL;
// 	extract_sz = 0;
// 	for (int i = 0; i < count; i++)
// 	{
// 		extract_sz += ft_strlen(extract_el[i]) + 1;
// 	}
// 	extract_str = malloc(extract_sz);
// 	if (extract_str == NULL)
// 	{
// 		free(extract_el);
// 		return (NULL);
// 	}
// 	extract_str[0] = '\0';
// 	for (int i = 0; i < count; i++)
// 	{
// 		ft_strcat(extract_str, extract_el[i]);
// 		ft_strcat(extract_str, "\n");
// 	}
// 	deallocate(extract_el);
// 	return (extract_str);
// }