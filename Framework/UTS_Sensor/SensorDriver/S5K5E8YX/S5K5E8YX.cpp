# i n c l u d e   " S t d A f x . h "  
 # i n c l u d e   " S 5 K 5 E 8 Y X . h "  
 # i n c l u d e   " C o m m o n F u n c . h "  
  
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 S 5 K 5 E 8 Y X : : S 5 K 5 E 8 Y X ( )  
 {  
 	 n a m e   =   _ T ( " S 5 K 5 E 8 Y X " ) ;  
 	 s e n s o r T y p e   =   S e n s o r _ S 5 K 5 E 8 Y X ;  
         s i d _ l e n   =   5 ;  
 }  
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 i n t   S 5 K 5 E 8 Y X : : d o _ p r o g _ o t p ( i n t   p a g e ,   i n t   a d d r ,   c o n s t   v o i d   * d a t a ,   i n t   l e n )  
 {  
 	 u i n t 8 _ t   * c D a t a   =   ( u i n t 8 _ t   * ) d a t a ;  
 	 c h a r   B u r n O t p D a t a [ 6 4 ] ;  
 	 c h a r   R e a d O t p D a t a [ 6 4 ] ;  
 	 c h a r   B u r n D a t a ;  
 	 c h a r   R e a d D a t a ;  
 	 i n t   r e t r y c o u n t   =   0 ;  
  
 	 m e m s e t ( B u r n O t p D a t a ,   0 ,   6 4 ) ;  
 	 m e m s e t ( R e a d O t p D a t a ,   0 ,   6 4 ) ;  
  
 	 f o r ( i n t   i = 0 ;   i < l e n ;   i + + ) {  
 	 	 B u r n O t p D a t a [ i ]   =   c D a t a [ i ] ;  
 	 }  
  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 3 B 4 0 , 0 x 0 0 ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 3 B 4 5 , 0 x 0 1 ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 0 , 0 x 0 4 ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 2 , p a g e ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 0 , 0 x 0 3 ) ;  
 	 f o r ( i n t   i = 0 ; i < l e n ; i + + )  
 	 {  
 	 	 B u r n D a t a   =   0 ;  
 	 	 B u r n D a t a   =   B u r n O t p D a t a [ i ] ;  
 	 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , i + a d d r , B u r n D a t a ) ;  
  
 	 	 S l e e p ( 1 ) ;  
 	 	 R e a d D a t a   =   d e v - > i 2 c _ r e a d ( B I T 1 6 _ B I T 8 , i + a d d r ) ;  
  
 	 	 w h i l e ( ( ( B u r n D a t a )   ! =   R e a d D a t a )   & &   ( r e t r y c o u n t   <   1 0 ) )  
 	 	 {  
 	 	 	 r e t r y c o u n t + + ;  
 	 	 	 B u r n D a t a   =   0 ;  
 	 	 	 B u r n D a t a   =   B u r n O t p D a t a [ i ] ;  
 	 	 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , i + a d d r , B u r n D a t a ) ;  
 	 	 	 R e a d D a t a   =   d e v - > i 2 c _ r e a d ( B I T 1 6 _ B I T 8 , i + a d d r ) ;  
 	 	 }  
  
 	 	 i f ( r e t r y c o u n t > = 1 0 )   r e t u r n   - 2 ;  
 	 	 r e t r y c o u n t   =   0 ;  
 	  
 	 }  
 	 / / S l e e p ( 5 0 0 ) ;  
 	 S l e e p ( 3 0 ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 0 , 0 x 0 4 ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 0 , 0 x 0 0 ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 3 B 4 0 , 0 x 0 1 ) ;  
         r e t u r n   0 ;  
 }  
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 i n t   S 5 K 5 E 8 Y X : : d o _ r e a d _ o t p ( i n t   p a g e ,   i n t   a d d r ,   v o i d   * d a t a ,   i n t   l e n )  
 {  
 	 u n s i g n e d   c h a r   * c D a t a   =   ( u n s i g n e d   c h a r   * ) d a t a ;  
 	 i n t   s t a r A d d r   =   a d d r ;  
 	 i n t   e n d A d d r   =   a d d r   +   l e n   - 1 ;  
  
 	 u n s i g n e d   c h a r   R e a d O t p V a l u e ;  
  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 0 , 0 x 0 4 ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 2 , p a g e ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 0 , 0 x 0 1 ) ;  
 	 f o r ( i n t   i = 0 ; i < l e n ; i + + )  
 	 {  
 	 	 R e a d O t p V a l u e   =   0 ;  
 	 	 R e a d O t p V a l u e = d e v - > i 2 c _ r e a d ( B I T 1 6 _ B I T 8 , a d d r + i ) ;  
 	 	 c D a t a [ i ]   =   R e a d O t p V a l u e ;  
 	 }  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 0 , 0 x 0 4 ) ;  
       r e t u r n   0 ;  
 }  
  
 i n t   S 5 K 5 E 8 Y X : : d o _ g e t _ s i d ( u i n t 8 _ t   * i d )  
 {  
         i f   ( d o _ r e a d _ o t p ( 0 ,   0 x 0 a 0 4 ,   ( c h a r * ) i d ,   s i d _ l e n )   <   0 )  
         {  
                 r e t u r n   - 1 ;  
         }  
         r e t u r n   0 ;  
 }  
  
 B O O L   S 5 K 5 E 8 Y X : : G e t S e n s o r I d ( _ _ o u t   C S t r i n g   & s t r S e n s o r I d )  
 {  
 	 s t r S e n s o r I d   =   E M P T Y _ S T R ;  
 # i f   0  
   	 W O R D   w F u s e I d [ 1 6 ]   =   { 0 } ;  
 	 f o r   ( s i z e _ t   i   =   0 ;   i   <   A R R A Y _ S I Z E ( w F u s e I d ) ;   i + + )  
 	 {  
 	 	 i f   ( ! d e v - > r e a d _ s e n s o r ( 0 x 0 a 0 4   +     i ,   w F u s e I d [ i ] ) )  
 	 	 {  
 	 	 	 p r i n t k ( _ T ( " R e g R e a d   E r r o r .   [ R e g   =   0 x % x ] [ D a t a   =   0 x % x ] " ) ,  
 	 	 	 	 0 x 7 0 0 0   +   i ,   w F u s e I d [ i ] ) ;  
 	 	 	 r e t u r n   F A L S E ;  
 	 	 }  
 	 	 / /   � � � � F U S E _ I D � � � � S e n s o r I d  
 	 	 s t r S e n s o r I d . A p p e n d F o r m a t ( _ T ( " % 0 2 X " ) ,   w F u s e I d [ i ] ) ;  
 	 }  
 # e n d i f  
  
 	 s t r S e n s o r I d   =   E M P T Y _ S T R ;  
 	 / /   � � � � � � � � � � � � � �  
 	 / * c h a r   d a t a [ 2 ] ;  
  
 	 d a t a [ 0 ] =   0 x 0 4 ;  
 	 d a t a [ 1 ] =   0 x 0 0 ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 ,   0 x 0 A 0 0 ,   d a t a ,   2 ) ;  
  
 	 d a t a [ 0 ] =   0 x 0 0 ;  
 	 d a t a [ 1 ] =   0 x 0 0 ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 ,   0 x 0 A 0 2 ,   d a t a ,   2 ) ;  
  
 	 d a t a [ 0 ] =   0 x 0 1 ;  
 	 d a t a [ 1 ] =   0 x 0 0 ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 ,   0 x 0 A 0 0 ,   d a t a ,   2 ) ;  
 	 * /  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 0 , 0 x 0 4 ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 2 , 0 x 0 0 ) ;  
 	 d e v - > i 2 c _ w r i t e ( B I T 1 6 _ B I T 8 , 0 x 0 A 0 0 , 0 x 0 1 ) ;  
  
 	  
 	 / /   � � � � F U S E _ I D  
 	 W O R D   w F u s e I d [ 8 ]   =   { 0 } ;  
 	 f o r   ( s i z e _ t   i   =   0 ;   i   <   A R R A Y _ S I Z E ( w F u s e I d ) ;   i + + )  
 	 {  
 	 	 i f   ( ! d e v - > r e a d _ s e n s o r ( 0 x 0 A 0 4   +   i ,   w F u s e I d [ i ] ) )  
 	 	 {  
 	 	 	 p r i n t k ( _ T ( " R e g R e a d   E r r o r .   [ R e g   =   0 x % x ] [ D a t a   =   0 x % x ] " ) ,  
 	 	 	 	               0 x 0 A 2 4   +   i ,   w F u s e I d [ i ] ) ;  
 	 	 	 r e t u r n   F A L S E ;  
 	 	 }  
 	 	 / /   � � � � F U S E _ I D � � � � S e n s o r I d  
 	 	 s t r S e n s o r I d . A p p e n d F o r m a t ( _ T ( " % 0 2 X " ) ,   w F u s e I d [ i ] ) ;  
 	 }  
  
 	 r e t u r n   T R U E ;  
 }  
  
 i n t   S 5 K 5 E 8 Y X : : w b _ w r i t e b a c k ( u i n t 8 _ t   * r e g s ,   i n t   l e n )  
 {  
 / /   	 d e v - > w r i t e _ s e n s o r ( 0 x 5 0 3 2 ,   r e g s ,   l e n ) ;  
 / /    
   	 i n t   v a l   =   d e v - > r e a d _ s e n s o r ( 0 x 5 0 0 0 ) ;  
   	 d e v - > w r i t e _ s e n s o r ( 0 x 5 0 0 0 ,   v a l   |   0 x 0 8 ) ;  
 / *  
 	 d e v - > w r i t e _ s e n s o r ( 0 x 5 0 1 4 ,   r e g s [ 0 ]   > >   8 ) ;  
 	 d e v - > w r i t e _ s e n s o r ( 0 x 5 0 1 5 ,   r e g s [ 0 ]   &   0 x 0 0 f f ) ;  
  
 	 d e v - > w r i t e _ s e n s o r ( 0 x 5 0 1 2 ,   r e g s [ 1 ]   > >   8 ) ;  
 	 d e v - > w r i t e _ s e n s o r ( 0 x 5 0 1 3 ,   r e g s [ 1 ]   &   0 x 0 0 f f ) ;  
  
 	 d e v - > w r i t e _ s e n s o r ( 0 x 5 0 0 0 ,   r e g s [ 0 ]   > >   8 ) ;  
 	 d e v - > w r i t e _ s e n s o r ( 0 x 5 0 0 1 ,   r e g s [ 0 ]   &   0 x 0 0 f f ) ;  
 * /  
 	 r e t u r n   0 ;  
 }  
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
  
 