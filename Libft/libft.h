/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:12:48 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/07/19 19:52:23 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_stk
{
	void			*content;
	struct s_stk	*first;
	struct s_stk	*next;
}					t_stk;

/*
*	@brief		Checks for an alphabetic character.
*
*	@param		c	Character to check.
*
*	@return		1 if c is an alphabetic character, 0 otherwise.
*/
int		ft_isalpha(int c);

/*
*	@brief		Checks for a digit (0 through 9).
*
*	@param		c	Character to check.
*
*	@return		1 if c is a digit, 0 otherwise.
*/
int		ft_isdigit(int c);

/*
*	@brief		Checks for an alphanumeric character.
*
*	@param		c	Character to check.
*
*	@return		1 if c is an alphanumeric character, 0 otherwise.
*/
int		ft_isalnum(int c);

/*
*	@brief		Checks for an ASCII character.
*
*	@param		c	Character to check.
*
*	@return		1 if c is an ASCII character, 0 otherwise.
*/
int		ft_isascii(int c);

/*
*	@brief		Checks for any printable character including space.
*
*	@param		c	Character to check.
*
*	@return		1 if c is a printable character, 0 otherwise.
*/
int		ft_isprint(int c);

/*
*	@brief		Counts the number of characters in a string.
*
*	@param		s	String to count.
*
*	@return		Number of characters in s.
*/
int		ft_strlen(const char *s);

/*
*	@brief		Fills the first n bytes of the memory area pointed to by s with
*				the constant byte c.
*
*	@param		s	Pointer to the memory area to fill.
*	@param		c	Constant byte to fill the memory area with.
*	@param		n	Number of bytes to fill.
*
*	@return		Pointer to the memory area s.
*/
void	*ft_memset(void *s, int c, size_t n);

/*
*	@brief		Fills the first n bytes of the memory area pointed to by s with
*				the constant byte 0.
*
*	@param		s	Pointer to the memory area to fill.
*	@param		n	Number of bytes to fill.
*
*	@return		Pointer to the memory area s.
*/
void	*ft_bzero(void *s, size_t n);

/*
*	@brief		Copies n bytes from memory area src to memory area dest.
*
*	@param		dest	Pointer to the destination memory area.
*	@param		src		Pointer to the source memory area.
*	@param		n		Number of bytes to copy.
*
*	@return		Pointer to the destination memory area dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/*
*	@brief		Copies len bytes from string src to string dst. The two strings
*				may overlap; the copy is always done in a non-destructive
*				manner.
*
*	@param		dst	Pointer to the destination array where the content is to
*					be copied, type-casted to a pointer of type void*.
*	@param		src	Pointer to the source of data to be copied, type-casted to
*					a pointer of type void*. The content of the array pointed by
*					src is copied to the array pointed by dst.
*	@param		n	Number of bytes to copy.
*
*	@return		Pointer to the destination array dst.
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/*
*	@brief		Copies up to size - 1 characters from the NUL-terminated string
*				src to dst, NUL-terminating the result.
*
*	@param		dst		Pointer to the destination array where the content is to
*						be copied, type-casted to a pointer of type char*.
*	@param		src		Pointer to the source of data to be copied, type-casted 
*						to a pointer of type char*. The content of the array
*						pointed by src is copied to the array pointed by dst.
*	@param		size	Maximum number of bytes to be used in the destination
*						array dst. The size of the resulting string in dst is
*						always less than or equal to size.
*
*	@return		The total length of the string they tried to create.
*/
int		ft_strlcpy(char *dest, const char *src, size_t size);

/*
*	@brief		Appends string src to the end of dst. It will append at most
*				size - strlen(dst) - 1 bytes, NUL-terminating the result.
*
*	@param		dst		Pointer to the destination array where the content is to
*						be copied, type-casted to a pointer of type char*. The
*						string pointed to by src is appended to the end of the
*						string pointed to by dst. The initial character of src
*						overwrites the null character at the end of dst.
*	@param		src		Pointer to the source of data to be copied, type-casted
*						to a pointer of type char*.
*	@param		size	Maximum number of bytes to be used in the destination
*						array dst. The size of the resulting string in dst is
*						always less than or equal to size.
*
*	@return		The total length of the string they tried to create.
*/
int		ft_strlcat(char *dest, const char *src, size_t size);

/*
*	@brief		Converts char c to uppercase letter in case of being a
*				lowercase letter.
*
*	@param		c	Char to be converted to uppercase.
*
*	@return		Char c converted to uppercase if it was lowercase, char
*				c otherwise.
*/
int		ft_toupper(int c);

/*
*	@brief		Converts char c to lowercase letter in case of being a
*				uppercase letter.
*
*	@param		c	Char to be converted to lowercase.
*
*	@return		Char c converted to lowercase if it was uppercase, char
*				c otherwise.
*/
int		ft_tolower(int c);

/*
*	@brief		Looks for the first occurrence of the character c in the 
*				string s. Returns NULL if the character was not found.
*
*	@param		s	String to be searched.
*	@param		c	Character to be searched for.
*
*	@return		Pointer to the first occurrence of the character c in the 
*				string s. Returns NULL if the character was not found.
*/
char	*ft_strchr(const char *s, int c);

/*
*	@brief		Looks for the last occurrence of the character c in the 
*				string s.
*
*	@param		s	String to be searched.
*	@param		c	Character to be searched for.
*
*	@return		Pointer to the last occurrence of the character c in the
*				string s.
*/
char	*ft_strrchr(const char *s, int c);

/*
*	@brief		Compares the first n chars of the strings s1 and s2.
*
*	@param		s1	Pointer to the first string to be compared.
*	@param		s2	Pointer to the second string to be compared.
*	@param		n	Number of chars to be compared.
*
*	@return		0 if the strings are equal, a negative number if the first
*				different char in s1 is less than the first different char in
*				s2, a positive number if the first different char in s1 is
*				greater than the first different char in s2.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
*	@brief		Looks for the first instance of c in the first n bytes of 
*				memory starting from s. If no instance is found, returns NULL.
*				
*
*	@param		s	Area of memory to be searched.
*	@param		c	Character to be searched for in memory.
*	@param		n	Number of bytes to be searched.
*
*	@return		Pointer to the first instance of c in the first n bytes of
*				memory starting from s. If no instance is found, returns NULL.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/*
*	@brief		Compares the first n bytes of s1 and s2 areas of memory,
*				interpreting each byte as unsigned char.
*
*	@param		s1	Pointer to the first area of memory to be compared.
*	@param		s2	Pointer to the second area of memory to be compared.
*	@param		n	Number of bytes to be compared.
*
*	@return		0 if the areas of memory are equal, a negative number if the 
*				first different byte in s1 is less than the first different 
*				byte in s2, a positive number if the first different byte in 
*				s1 is greater than the first different byte in s2.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
*	@brief		Locates the first occurrence of the null-terminated
*    			string to_find in the null-terminated string str.
*
*	@param		str			String to be searched.
*	@param		to_find		String to be searched for.
*
*	@return		Pointer to the first occurrence of the null-terminated
*    			string to_find in the null-terminated string str. If the
*				string to_find is not found, returns NULL. If to_find is an
*				empty string, returns str.
*/
char	*ft_strnstr(const char	*str, const char *to_find, size_t len);

/*
*	@brief		Converts the initial portion of the string pointed to by
*				str to int. Discards any whitespace characters until the
*				first non-whitespace character is found. Then takes as many
*				characters as possible to form a valid integer representation
*				and converts them to an integer. The string can contain
*				optional plus or minus sign. If the first sequence of
*				non-whitespace characters in str is not a valid integral
*				number, or if no such sequence exists because either str is
*				empty or it contains only whitespace characters, no conversion
*				is performed and zero is returned.
*
*	@param		str		String to be converted to int.
*
*	@return		The converted integral number as an int value. If no valid
*				conversion could be performed, a zero value is returned.
*/
int		ft_atoi(const char *str);

/*
*	@brief		Allocates memory for an array of nmemb elements of size bytes 
*				each and returns a pointer to the allocated memory. The memory 
*				is set to zero. If nmemb or size is 0, then calloc() returns 
*				unique pointer value that can later be successfully passed
*				to free().
*
*	@param		nmemb	Number of elements to be allocated.
*	@param		size	Size of each element.
*
*	@return		Pointer to the allocated memory. If the function fails, it
*				returns NULL.
*/
void	*ft_calloc(size_t nmemb, size_t size);

/*
*	@brief		Returns a pointer to a new string which is a duplicate of
*        		the string str.  Memory for the new string is obtained with 
*      			malloc(3), and can be freed with free(3).
*
*	@param		str		String to be duplicated.
*
*	@return		Pointer to the duplicated string. If the function fails, it
*				returns NULL.
*/
char	*ft_strdup(const char *str);

/*
*	@brief		Creates a substring of the string s. Memory for the new string  
*      			is obtained with malloc(3), and can be freed with free(3). The
*				substring starts from index start and has a maximum length of
*				len.
*
*	@param		s		String to extract the substring from.
*	@param		start	Index to start the substring from.
*	@param		len		Maximum length of the substring.
*
*	@return		Pointer to the substring. If the function fails, it returns NULL.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
*	@brief		Creates a new string allocating memory with malloc(3) joining
*				strings s1 and s2.
*
*	@param		s1	First string to be joined.
*	@param		s2	Second string to be joined.
*
*	@return		Pointer to the string created from joining strings s1 and s2.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
*	@brief		Removes characters specified in set from the beginning and
*				the end of the string s1. Memory for the new string is
*				obtained with malloc(3), and can be freed with free(3).
*
*	@param		s1		String to be trimmed.
*	@param		set		Characters to be removed from the beginning and the
*						end of the string s1.
*
*	@return		Pointer to the trimmed string. If the function fails, it
*				returns NULL.
*/
char	*ft_strtrim(char const *s1, char const *set);

/*
*	@brief		Allocates (with malloc(3)) an array of strings that results 
*				from splitting string s into substrings using char c as the
*				delimiter. The array ends with a NULL pointer.
*
*	@param		s	String to split.
*	@param		c	Char used as delimiter.
*
*	@return		The array of strings that results from splitting string s.
*				NULL if memory allocation fails.
*/
char	**ft_split(char const *s, char c);

/*
*	@brief		Allocates (with malloc(3)) and returns a string representing
*				the integer received as an argument. Negative numbers are
*				handled.
*
*	@param		n	Integer to be converted to string.
*
*	@return		The string representing the integer. NULL if memory allocation
*				fails.
*/
char	*ft_itoa(int n);

/*
*	@brief		Applies the function f to each character of the string s
*				to create a new string (with malloc(3)) resulting from
*				successive applications of f.
*
*	@param		s	String to be mapped.
*	@param		f	Function to apply to each character of s.
*
*	@return		The string created from the successive applications of f.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
*	@brief		Applies the function f to each character of the string s
*				as a parameter. Each character is passed by address to f
*				to be modified if necessary.
*
*	@param		s	String to be iterated.
*	@param		f	Function to apply to each character of s.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
*	@brief		Outputs the character c to the given file descriptor.
*
*	@param		c	Character to output.
*	@param		fd	File descriptor on which to write.
*/
void	ft_putchar_fd(char c, int fd);

/*
*	@brief		Outputs the string s to the given file descriptor.
*
*	@param		s	String to output.
*	@param		fd	File descriptor on which to write.
*/
void	ft_putstr_fd(char *s, int fd);

/*
*	@brief		Outputs a section of the string s to the given file
*				descriptor fd, printing len characters.
*
*	@param		s	String to output.
*	@param		len		Number of characters to print.
*	@param		fd	File descriptor on which to write.
*/
void	ft_putstrn_fd(char *s, int len, int fd);

/*
*	@brief		Outputs the string s to the given file descriptor, followed
*				by a newline.
*
*	@param		s	String to output.
*	@param		fd	File descriptor on which to write.
*/
void	ft_putendl_fd(char *s, int fd);

/*
*	@brief		Outputs the long n to the given file descriptor.
*
*	@param		n	Long to output.
*	@param		fd	File descriptor on which to write.
*/
void	ft_putnbr_fd(long n, int fd);

/*
*	@brief		Outputs the long n to the given file descriptor, following the
*				string base. The length of base determines the numeric base.
*				The number will only be printed if the base does not contain
*				repeated characters and does not contain '-' and/or '+'.
*
*	@param		n		Long to print in the given base.
*	@param		base	Base with which n will be interpreted.
*	@param		fd		File descriptor on which to write.
*/
void	ft_putnbr_base_fd(long nbr, char *base, int fd);

/*
*	@brief		Outputs the unsigned long n to the given file descriptor, following 
*				the string base. The length of base determines the numeric base.
*				The number will only be printed if the base does not contain
*				repeated characters and does not contain '-' and/or '+'.
*
*	@param		n		Unsigned long to print in the given base.
*	@param		base	Base with which n will be interpreted.
*	@param		fd		File descriptor on which to write.
*/
void	ft_putunbr_base_fd(unsigned long long nbr, char *base, int fd);

/*
*	@brief		Allocates (with malloc(3)) and returns a new list node. The
*				variable content is initialized with the value of the parameter
*				content. The variable next is initialized to NULL.
*
*	@param		content	Content of the new list node.
*
*	@return		The new list node. NULL if memory allocation fails.
*/
t_list	*ft_lstnew(void *content);

/*
*	@brief		Adds the node lst at the beginning of the list.
*
*	@param		*lst	Pointer to the first node of the list.
*	@param		*new_node	Pointer to the node to add to the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new_node);

/*
*	@brief		Returns the number of nodes in the list.
*
*	@param		*lst	Pointer to the first node of the list.
*
*	@return		The number of nodes in the list.
*/
int		ft_lstsize(t_list *lst);

/*
*	@brief		Returns the last node of the list.
*
*	@param		*lst	Pointer to the first node of the list.
*
*	@return		The last node of the list.
*/
t_list	*ft_lstlast(t_list *lst);

/*
*	@brief		Adds the node lst at the end of the list.
*
*	@param		*lst	Pointer to the first node of the list.
*	@param		*new_node	Pointer to the node to add to the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new_node);

/*
*	@brief		Deletes and frees the given list node using the function del
*				given as a parameter and free(3). The memory of next must not
*				be freed.
*
*	@param		*lst	Pointer to the list node to be deleted.
*	@param		*del	Function used to delete the content of the list node.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/*
*	@brief		Deletes and frees the given list using the function del given
*				as a parameter and free(3). The pointer to the first node of
*				the list must be set to NULL.
*
*	@param		*lst	Pointer to the first node of the list.
*	@param		*del	Function used to delete the content of the list node.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*));

/*
*	@brief		Iterates the list lst and applies the function f to the content
*				of each node.
*
*	@param		*lst	Pointer to the first node of the list.
*	@param		*f		Function to apply to the content of each node.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*
*	@brief		Iterates the list lst and applies the function f to the content
*				of each node. Creates a new list resulting of the successive
*				applications of the function f. The del function is used to
*				delete the content of a node if needed.
*
*	@param		*lst	Pointer to the first node of the list.
*	@param		*f		Function to apply to the content of each node.
*	@param		*del	Function used to delete the content of a node if needed.
*
*	@return		The new list. NULL if memory allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
*	@brief		Counts the number of ocurrences of the character c in 
*				the string str.
*
*	@param		*str	String to be searched.
*	@param		c		Character to count.
*
*	@return		The number of ocurrences of the character.
*/
int		ft_count_char(char *str, char c);

/*
*	@brief		Inserts the list `new` where the node `old` from the list
*				that starts with the node `start` and deletes the node `old`. 
*
*	@param		*start	Node that starts the list to be modified.
*	@param		*old	Node to be replaced.
*	@param		*new	List to be inserted in old's place.
*	@param		*del	Function pointer used to delete the old node.
*
*	@return		The node at the start of the modified list.
*/
t_list	*ft_lstrpl(t_list *bg, t_list *old, t_list *new, void (*del)(void *));

/*
*	@brief		Removes the list node `to_pop` from the list `lst`, conecting
*				the previous node to the next. Returns the removed node.
*
*	@param		*lst	List from which a node will be popped.
*	@param		*to_pop	Node to be popped.
*
*	@return		The node that was popped.
*/
t_list	*ft_lstpop(t_list **lst, t_list *to_pop);

/*
*	@brief		Removes the list node in the position `idx` from the list `lst`, 
*				conecting the previous node to the next. Returns the removed node.
*
*	@param		*lst	List from which a node will be popped.
*	@param		*idx	Index of the node to be popped.
*
*	@return		The node that was popped.
*/
t_list	*ft_lstpop_idx(t_list *lst, int idx);

/*
*	@brief		Allocates (with malloc(3)) and returns a new stack node. The
*				variable content is initialized with the value of the parameter
*				content. The variable next is initialized to NULL. The node created
*				is assigned as the first element of its own stack.
*
*	@param		content	Content of the new stack node.
*
*	@return		The new stack node. NULL if memory allocation fails.
*/
t_stk	*ft_stknew(void *content);

/*
*	@brief		Returns the last element of the stack.
*
*	@param		stk	Stack out of which the last element will be returned.
*
*	@return		The last element of the stack.
*/
t_stk	*ft_stklast(t_stk *stk);

/*
*	@brief		Gets the index of the stack node `search` in the stack `stk`. Returns
*				-1 if the node wasn't found.
*
*	@param		stk	Stack to be searched.
*	@param		search	Stack node to search.
*
*	@return		The index of the searched node within the stack, 
*				-1 if is not present or error.
*/
int		ft_getstkidx(t_stk *stk, t_stk *search);

/*
*	@brief		Gets the size of the stack.
*
*	@param		stk	Stack to get the size of.
*
*	@return		The size of the stack. -1 if the node passed is not the first element.
*/
int		ft_stksize(t_stk *stk);

/*
*	@brief		Gets the element in the position `idx` in the stack `stk`.
*
*	@param		stk	Stack where the node will be searched.
*	@param		idx	Index of the element to get.
*
*	@return		The node in position `idx` or NULL if error or node not present.
*/
t_stk	*ft_getstknode(t_stk *stk, int idx);

/*
*	@brief		Sets the node `new_first` as the new first node of stack `stk`.
*
*	@param		stk			Stack in where the first position will change.
*	@param		new_first	Node that will become the first in the stack.
*/
void	ft_stknewfirst(t_stk *stk, t_stk *new_first);

/*
*	@brief		Inserts the stack node `new` into `stk` and makes it the first node.
*
*	@param		stk	Stack where the node will be inserted.
*	@param		new	New stack node that will be added. It will become the first node.
*/
void	ft_stkadd_top(t_stk *stk, t_stk *new_node);

/*
*	@brief		Deletes and frees the given stack node using the function del
*				given as a parameter and free(3). The memory of next must not
*				be freed.
*
*	@param		*stk	Pointer to the stack node to be deleted.
*	@param		*del	Function used to delete the content of the stack node.
*/
void	ft_stkdelone(t_stk *stk, void (*del)(void*));

/*
*	@brief		Deletes and frees the given stack using the function del given
*				as a parameter and free(3). The pointer to the first node of
*				the stack must be set to NULL.
*
*	@param		*stk	Pointer to the first node of the stack.
*	@param		*del	Function used to delete the content of the stack node.
*/
void	ft_stkclear(t_stk **stk, void (*del)(void*));

/*
*	@brief		Iterates the stack `stk` and applies the function f to the content
*				of each node.
*
*	@param		*stk	Pointer to a node of a stack.
*	@param		*f		Function to apply to the content of each node.
*/
void	ft_stkiter(t_stk *stk, void (*f)(void *));

/*
*	@brief		Removes the stack node `to_pop` from the stack `stk`, connecting
*				the previous node to the next. Returns the removed node.
*
*	@param		*stk	Stack from which a node will be popped.
*	@param		*to_pop	Node to be popped.
*
*	@return		The node that was popped, NULL if error.
*/
t_stk	*ft_stkpop(t_stk **stk, t_stk *to_pop);

/*
*	@brief		Removes the stack node in the position `idx` from the stack `stk`, 
*				conecting the previous node to the next. Returns the removed node.
*
*	@param		*stk	Stack from which a node will be popped.
*	@param		*idx	Index of the node to be popped.
*
*	@return		The node that was popped.
*/
t_stk	*ft_stkpop_idx(t_stk *stk, int idx);

/*
*	@brief		Rotates the whole stack `stk` upwards, moving the previous first
*				element to the last position.
*
*	@param		*stk	The stack to be rotated.
*/
void	ft_stk_r(t_stk *stk);

/*
*	@brief		Rotates the whole stack `stk` downwards, moving the previous last
*				element to the first position.
*
*	@param		*stk	The stack to be rotated.
*/
void	ft_stk_rr(t_stk *stk);

/*
*	@brief		Pushes the first element from the stack `orig` to the stack
*				`dest`. The second element from `orig` becomes the first and
*				that element pushed is added to the top of the stack `dest`.
*
*	@param		*orig	The stack from which the first element will be popped.
*	@param		*dest	The stack onto which the popped element will be added.
*/
void	ft_stk_p(t_stk **orig, t_stk **dest);

/*
*	@brief		Swaps position of the first two elements of the stack `stk`.
*
*	@param		*stk	The stack in which the two first elements will be swapped.
*/
void	ft_stk_s(t_stk *stk);

/*
*	@brief		Sorts an array using the quick sort algorithm in ascending order.
*
*	@param		arr		The array to be sorted.
*	@param		start	The index of the first element in the array to be sorted.
*	@param		end		The index of the last element in the array to be sorted.
*/
void	quick_sort(int arr[], int start, int end);

/*
*	@brief		Calculates the absolute value of an integer n.
*
*	@param		*n	Number to calculate the absolute value of.
*
*	@return		The absolute value of n.
*/
int		ft_abs(int n);

/*
*	@brief		Returns the smallest or the biggest integer, either a or b,
*				depending on the state of find_min.
*
*	@param		*a	Integer to compare.
*	@param		*b	Integer to compare.
*	@param		*find_min	Boolean that determines the type of comparison.
*
*	@return		The smallest integer if find_min is 1, the biggest if it is 0.
*/
int		ft_minmax(int a, int b, int find_min);

/*
*	@brief		Converts a number codified in the string str in certain base
*				into an integer.
*
*	@param		*str	String that represents the integer to convert.
*	@param		*base	String of elements in order that represent the base in
*						which str is codified. For example, "0123456789ABCDEF"
*						is the standard hexadecimal base.
*
*	@return		The integer interpreted from the string using the base. Effectively
*				changes the base of the number contained in str from strlen(base) to
*				base 10.
*/
int		ft_atoi_base(char *str, char *base);

/*
*	@brief		Function like calloc but that registers the pointer created into
*				the linked list alloc to be able to free it later.
*
*	@param		nmemb	Number of members to reserve memory for.
*	@param		size	Size of each member in bytes.
*	@param		**alloc	Linked list into which the pointer created will be appended.
*
*	@return		The pointer for which the memory was allocated.
*/
void	*ft_reg_calloc(size_t nmemb, size_t size, t_list **alloc);

#endif