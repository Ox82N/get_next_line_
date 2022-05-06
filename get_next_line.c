/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:44:25 by obenjair          #+#    #+#             */
/*   Updated: 2022/05/06 17:00:02 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int count(char *stash)
{
    int i;

    i = 0;
    while(stash[i] != '\0')
    {
        if(stash[i] == '\n')
		{
            i += 1;
            break;
		}
    i++;
    }
    return i;
}
char *ft_line(char *stash)
{
    int i;
    int n;
    char *line;

    line = NULL;
    if (stash == NULL)
        return NULL;
    i = count(stash);
    n = 0;
    line = (char *)malloc(sizeof(char) * (i + 1));
    if (line == NULL)
        return NULL;
    while (n < i)
    {
        line[n] = stash[n];
        n++;
    }
	line[i] = '\0';
    return line;
}
char *ft_save_after_stash(char *stash)
{
    char *save;
    int i;
    int n;

    i = count(stash);
    n = 0;
    if (stash == NULL)
    {
        free(stash);
        return NULL;
    }
    save = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
    if (save == NULL)
        return NULL;
    while(stash[i + n])
    {
        save[n] = stash[i + n];
        n++;
    }
    save[n] = '\0';
    free(stash);
    return save;
}

char *ft_read_and_save(int fd, char *stash)
{
    char *buff;
    char *tmp;
    int nb;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return NULL;
    nb = 1;                    // the read function returns zero if the nbytes is zero
    while(nb != 0 && !(ft_strchr(stash, '\n')))
    {
        nb = read(fd, buff, BUFFER_SIZE);
        if (nb == -1)
        {
            free(buff);
            return NULL;
        }
        buff[nb] = '\0';
        tmp = ft_strjoin(stash, buff);
        free(stash);
        stash = tmp;
    }
    free(buff);
    return stash;
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    stash = ft_read_and_save(fd, stash);
    if (stash == NULL)
        return NULL;
    line = ft_line(stash);
    stash = ft_save_after_stash(stash);
    if (line == NULL)
        return NULL;
    return line;
}
/*int main()
{
    //fd = open(test.txt, O_RDONLY);
    
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s", line);
        free(line);
        
    }
    return 0;
}*/
