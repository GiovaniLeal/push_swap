/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:02:07 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/26 20:20:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/*                        FUNÇÕES ESSENCIAIS PUSH SWAP                        */
/* ************************************************************************** */
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char sep);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);

/* ************************************************************************** */
/*                        FUNCOES DE LISTAS  (ESSENCIAIS)                     */
/* ************************************************************************** */

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}	t_list;

/* ------------ Funções de Lista Essenciais ------------ */
void	ft_lst_add_front(t_list **lst, t_list *new);
void	ft_lst_add_back(t_list **lst, t_list *new);
void	ft_lst_clear(t_list **lst, void (*del)(void *));
t_list	*ft_lst_last(t_list *lst);
t_list	*ft_lst_new(void *content);
int		ft_lst_size(t_list *lst);

#endif