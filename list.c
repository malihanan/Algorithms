//l i n k   l i s t :   c r e a t e ( w i t h   9 9 9 ) ,   p r i n t ,   r e v e r s e   p r i n t ,   a d d   a t   f r o n t ,   a d d   a t   l a s t ,   d e l e t e   f r o m   f r o n t ,   d e l e t e   a t   e nd
#i n cl u de<s t d i o . h >
#i n c l u d e < s t d l i b . h >
 
s t r u c t s t r u c t _ d a t a 
{ 
 	i n t  d a t a ;
 	 s t r u c t  s t r u c t _ d a t a  * n e x t ;
 } ; 
 t y p e d e f   s t r u c t   s t r u c t _ d a t a   n o d e ; 
   
 v o i d   c r e a t e (   n o d e   * * h e a d   ) ; 
 v o i d   p r i n t _ l i s t (   n o d e   * h e a d   ) ; 
 v o i d   r e v e r s e _ p r i n t _ l i s t (   n o d e   * h e a d   ) ; 
 v o i d   a d d _ f r o n t (   n o d e   * * h e a d ,   i n t   n ) ; 
 v o i d   a d d _ l a s t (   n o d e   * * h e a d ,   i n t   n ) ; 
 i n t   d e l e t e _ f r o n t (   n o d e   * * h e a d ) ; 
 i n t   d e l e t e _ l a s t (   n o d e   * * h e a d ) ; 
 
 i n t   m a i n ( ) 
 { 
 	 n o d e   * h e a d = N U L L ; 
 	 i n t   c h o i c e ,   n ; 
 	 p r i n t f ( " \ n E n t e r   v a l u e s   t o   m a k e   t h e   l i s t :   " ) ; 
 	 p r i n t f ( " \ n E n t e r   9 9 9   t o   e n d   t h e   l i s t ! \ n " ) ; 
 	 c r e a t e ( & h e a d ) ; 
 	 
 	 p r i n t f ( " \ n T h e   l i s t   i s :   \ n " ) ; 
 	 p r i n t _ l i s t ( h e a d ) ; 
 	 p r i n t f ( " \ n T h e   r e v e r s e   l i s t   i s :   \ n " ) ; 
 	 r e v e r s e _ p r i n t _ l i s t ( h e a d ) ; 
 	 
 	 p r i n t f ( " \ n E n t e r   c h o i c e :   \ n " ) ; 
 	 p r i n t f ( " 1 .   A d d   i n   f r o n t \ n " ) ; 
 	 p r i n t f ( " 2 .   A d d   a t   t h e   e n d \ n " ) ; 
 	 p r i n t f ( " 3 .   D e l e t e   f r o m   f r o n t \ n " ) ; 
 	 p r i n t f ( " 4 .   D e l e t e   a t   t h e   e n d \ n " ) ; 
 	 s c a n f ( " % d " ,   & c h o i c e ) ; 
 	 
 	 s w i t c h ( c h o i c e ) 
 	 { 
 	 	 c a s e   1 : 
 	 	 	 p r i n t f ( " E n t e r   n o .   t o   b e   e n t e r e d : " ) ; 
 	 	 	 s c a n f ( " % d " ,   & n ) ; 
 	 	 	 a d d _ f r o n t ( & h e a d ,   n ) ; 
 	 	 	 p r i n t f ( " \ n N e w   l i s t : \ n " ) ; 
 	 	 	 p r i n t _ l i s t ( h e a d ) ; 
 	 	 	 b r e a k ; 
 	 	 	 
 	 	 c a s e   2 : 
 	 	 	 p r i n t f ( " E n t e r   n o .   t o   b e   e n t e r e d : " ) ; 
 	 	 	 s c a n f ( " % d " ,   & n ) ; 
 	 	 	 a d d _ l a s t ( & h e a d ,   n ) ; 
 	 	 	 p r i n t f ( " \ n N e w   l i s t : \ n " ) ; 
 	 	 	 p r i n t _ l i s t ( h e a d ) ; 
 	 	 	 b r e a k ; 
 	 	 	 
 	 	 c a s e   3 : 
 	 	 	 i f (   d e l e t e _ f r o n t ( & h e a d )   ) 
 	 	 	 { 
 	 	 	 	 p r i n t f ( " L i s t   i s   e m p t y ! " ) ; 
 	 	 	 } 
 	 	 	 e l s e 
 	 	 	 { 
 	 	 	 	 p r i n t f ( " \ n N e w   l i s t : \ n " ) ; 
 	 	 	 	 p r i n t _ l i s t ( h e a d ) ; 
 	 	 	 } 
 	 	 	 b r e a k ; 
 	 	 	 
 	 	 c a s e   4 : 
 	 	 	 i f (   d e l e t e _ l a s t ( & h e a d )   ) 
 	 	 	 { 
 	 	 	 	 p r i n t f ( " L i s t   i s   e m p t y ! " ) ; 
 	 	 	 } 
 	 	 	 e l s e 
 	 	 	 { 
 	 	 	 	 p r i n t f ( " \ n N e w   l i s t : \ n " ) ; 
 	 	 	 	 p r i n t _ l i s t ( h e a d ) ; 
 	 	 	 } 
 	 	 	 b r e a k ; 
 	 	 	 
 	 	 d e f a u l t : 
 	 	 	 p r i n t f ( " W r o n g   c h o i c e ! " ) ; 
 	 	 	 b r e a k ; 
 	 } 
 	 r e t u r n   0 ; 
 } 
   
 v o i d   c r e a t e (   n o d e   * * h e a d   ) 
 { 
 	 i n t   t e m p _ d a t a ; 
 	 n o d e   * n o d e 1 ; 
 	 s c a n f ( " % d " ,   & t e m p _ d a t a   ) ; 
 	 i f (   t e m p _ d a t a   = =   9 9 9   ) 
 	 { 
 	 	 r e t u r n ; 
 	 } 
 	 n o d e 1 = ( n o d e   * ) m a l l o c (   s i z e o f ( n o d e )   ) ; 
 	 n o d e 1 - > d a t a = t e m p _ d a t a ; 
 	 n o d e 1 - > n e x t = N U L L ; 
 	 * h e a d   =   n o d e 1 ; 
 	 c r e a t e (   & ( ( * h e a d ) - > n e x t )   ) ; 
 } 
 
 v o i d   p r i n t _ l i s t (   n o d e   * h e a d   ) 
 { 
 	 i f (   h e a d = = N U L L   ) 
 	 { 
 	 	 r e t u r n ; 
 	 } 
 	 p r i n t f ( " - >   % d " ,   h e a d - > d a t a   ) ; 
 	 p r i n t _ l i s t (   h e a d - > n e x t   ) ; 
 } 
 
 v o i d   r e v e r s e _ p r i n t _ l i s t (   n o d e   * h e a d   ) 
 { 
 	 i f (   h e a d = = N U L L   ) 
 	 { 
 	 	 r e t u r n ; 
 	 } 
 	 r e v e r s e _ p r i n t _ l i s t (   h e a d - > n e x t   ) ; 
 	 p r i n t f ( " - >   % d " ,   h e a d - > d a t a   ) ; 
 } 
 
 v o i d   a d d _ f r o n t (   n o d e   * * h e a d ,   i n t   n ) 
 { 
 	 n o d e   * n o d e 1 ; 
 	 n o d e 1 = ( n o d e   * ) m a l l o c (   s i z e o f ( n o d e )   ) ; 
 	 n o d e 1 - > d a t a = n ; 
 	 n o d e 1 - > n e x t = * h e a d ; 
 	 * h e a d = n o d e 1 ; 
 } 
 
 v o i d   a d d _ l a s t (   n o d e   * * h e a d ,   i n t   n ) 
 { 
 	 n o d e   * n o d e 1 ,   * t e m p ; 
 	 n o d e 1 = ( n o d e   * ) m a l l o c (   s i z e o f ( n o d e )   ) ; 
 	 n o d e 1 - > d a t a = n ; 
 	 n o d e 1 - > n e x t = N U L L ; 
 	 i f (   * h e a d = = N U L L   ) 
 	 { 
 	 	 * h e a d = n o d e 1 ; 
 	 	 r e t u r n ; 
 	 } 
 	 t e m p = * h e a d ; 
 	 w h i l e ( t e m p - > n e x t   ! =   N U L L   ) 
 	 { 
 	 	 t e m p = t e m p - > n e x t ; 
 	 } 
 	 t e m p - > n e x t = n o d e 1 ; 
 } 
 
 i n t   d e l e t e _ f r o n t (   n o d e   * * h e a d ) 
 { 
 	 n o d e   * t e m p ; 
 	 i f ( * h e a d   = =   N U L L   ) 
 	 	 r e t u r n ( 1 ) ; 
 	 t e m p = ( * h e a d ) - > n e x t ; 
 	 f r e e ( * h e a d ) ; 
 	 * h e a d = t e m p ; 
 	 r e t u r n ( 0 ) ; 
 } 
 
 i n t   d e l e t e _ l a s t (   n o d e   * * h e a d ) 
 { 
 	 n o d e   * t e m p ; 
 	 i f ( * h e a d   = =   N U L L   ) 
 	 	 r e t u r n ( 1 ) ; 
 	 t e m p = * h e a d ; 
 	 w h i l e ( t e m p - > n e x t   ! =   N U L L   ) 
 	 { 
 	 	 t e m p = t e m p - > n e x t ; 
 	 } 
 	 f r e e ( t e m p - > n e x t ) ; 
 	 r e t u r n ( 0 ) ; 
 }
