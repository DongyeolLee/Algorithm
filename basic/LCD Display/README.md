#LCD Display   
A friend of yours has just bought a new computer. Before this, the most powerful machine he ever used was a pocket calculator. He is a little disappointed because he liked the LCD display of his calculator more than the screen on his new computer! To make him happy, write a program that prints numbers in LCD display style.

##Input

The input file contains several lines, one for each number to be displayed. Each line contains integers s and n, where n is the number to be displayed ( 0 <= n <=99, 999, 999) and s is the size in which it shall be displayed ( 1 <= s <=10). The input will be terminated by a line containing two zeros, which should not be processed.

##Output

Print the numbers specified in the input file in an LCD display-style using s "-" signs for the horizontal segments and s "|" signs for the vertical ones. Each digit occupies exactly s + 2 columns and 2s + 3 rows. Be sure to fill all the white space occupied by the digits with blanks, including the last digit. There must be exactly one column of blanks between two digits.

Output a blank line after each number. You will find an example of each digit in the sample output below.

##Sample Input

2 12345   
3 67890   
0 0   

##Sample Output


 ````
      --   --        -- 
   |    |    | |  | |   
   |    |    | |  | |   
      --   --   --   -- 
   | |       |    |    |
   | |       |    |    |
      --   --        -- 

 ---   ---   ---   ---   --- 
|         | |   | |   | |   |
|         | |   | |   | |   |
|         | |   | |   | |   |
 ---         ---   ---       
|   |     | |   |     | |   |
|   |     | |   |     | |   |
|   |     | |   |     | |   |
 ---         ---   ---   --- 
 


