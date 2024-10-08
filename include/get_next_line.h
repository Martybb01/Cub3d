/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:02:42 by fdonati           #+#    #+#             */
/*   Updated: 2024/05/16 15:01:27 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/******************************************************************************/
/*                      Definizione BUFFER_SIZE se non definito in altro modo */
/******************************************************************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
/******************************************************************************/
/*						Definizione FD_MAX se non definito in altro modo      */
/******************************************************************************/
# ifndef FD_MAX
#  define FD_MAX 4096
# endif
/******************************************************************************/
/*						Librerie di supporto								  */
/******************************************************************************/
# include "libft.h"
/******************************************************************************/
/*						Funzioni principale									  */
/******************************************************************************/
char	*ft_get_next_line(int fd);
size_t	get_strlen(const char *s);
size_t	get_strlcpy(char *dst, const char *src, size_t size);
size_t	get_strlcat(char *dst, const char *src, size_t size);
char	*get_strchr(const char *s, int c);
char	*get_strljoin(const char *s1, char const *s2);

#endif
/******************************************************************************/
/*                     	DESCRIZIONE											  */
/* File: get_next_line.c | get_next_line_utils.c | get_next_line.h			  */
/* ---------------------													  */
/* Descrizione: 															  */
/* Questi file implementano la funzione get_next_line per la lettura		  */
/* incrementale da uno o piu' file descriptor.								  */
/*																			  */
/* Gestione FD:																  */
/* Il limite di 4096 file descriptor aperti è stato impostato per evitare	  */
/* l'esaurimento delle risorse del sistema. Tale limite è verificabile		  */
/* e configurabile attraverso il comando `ulimit`.							  */
/******************************************************************************/
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/*						GESTIONE FD											  */
/* Gestione dei Limiti dei File Descriptor con `ulimit`:					  */
/* -----------------------------------------------------					  */
/* - Controllare il limite soft corrente: `ulimit -Sn`						  */
/*   Mostra il max FD aperti permessi attualmente per l'utente.				  */
/*																			  */
/* - Controllare il limite hard corrente: `ulimit -Hn`						  */
/*   Mostra il max FD aperti consentiti, modificabile solo da root.			  */
/*																			  */
/* - Impostare un nuovo limite soft: `ulimit -Sn <nuovo_limite>`			  */
/*   Permette di modificare il limite soft fino al limite hard.				  */
/*																			  */
/* - Impostare un nuovo limite hard (root): `ulimit -Hn <nuovo_limite>`		  */
/*   Root può aumentare il limite hard fino a un nuovo valore.				  */
/*																			  */
/* Nota:																	  */
/* Modifiche al limite soft sono temporanee, ristabilite al riavvio.		  */
/* Per cambiamenti permanenti, modificare /etc/security/limits.conf,		  */
/* dopo averlo fatto dovrete temere ripercussioni da Davide.				  */
/******************************************************************************/
/*----------------------------------------------------------------------------*/