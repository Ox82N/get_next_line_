/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:49:11 by obenjair          #+#    #+#             */
/*   Updated: 2022/05/06 15:24:30 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int count(char *stash);
char *ft_line(char *stash);
char *ft_save_after_stash(char *stash);
char *ft_read_and_save(int fd, char *stash);
size_t	ft_strlen(const char *str);
int	ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);
#endif 
