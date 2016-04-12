# approximation-algorithm-for-decidability
All problems in this world can be classi?ed into polynomial and non-polynomial problems. Polynomial problems are those that are solvable in polynomial time. Non-polynomial problems are those problems which are not solvable in polynomial time but might be veri?able. Our problem aims to determine whether a given input program is polynomial or not using the help of a lexical analyzer and making use of recurrence equations to ?nd the time complexity. The ?nal output of our given project is a solution to an algorithm which determines if a given input code is polynomial or non-polynomial.

The system consists of 5 modules
1) Lexical Analyzer: 	
The lexical analyzer parses he input algorithm and returns as tokens the function name and the parameters of the function.
2) Module to find if Recursive: 
This module parses the program to determine if the token appears again in the program. If it does, we can state that the program is recursive.
3) Recursive Time complexity:
This module is called if the input algorithm is recursive. The recurrence equation of the program is found. This recurrence equation is solved to determine the time complexity.
4) Non Recursive Time Complexity:
For non recursive functions passed as input, the loops present inside the body are analyzed to determine the time complexity.
5) P or NP:		
This module takes as input the time complexity from the	previous modules and determines if the program is polynomial or not. Polynomial codes have a time complexity lesser that O(2^n). Non polynomial codes have a time complexity of O (2^n) and more.

Algorithm:

1)For non recursive time complexity module:

nonRecursiveTimeComplexity(FILE *ptr)  returns TimeComplexity 
	{
		if(no loop)
			complexity=O(1);
		else if(loop is present and runs till maximum value)
			complexity=O(n);
		else if(loop is found within loop)
			complexity=O(N^c);
		else if(loop value is multiplied or divided)
			complexity=O(log n);
		else if(loop value is increased/decreased exponentially)
			complexity=O(log logn);

		return complexity;
	}


2)Recursive time complexity module:

recursive(FILE *ptr, token) returns TimeComplexity
	{
		if(token() is found)
		{
			 a=numbers of times function is called recursively in a function block
			Analyze the parameters;
			
			case(parameters)
				(parameters/=2):
					b=parameters/2;
				(parameters-=1)
					b=parameters-1;
				…
				else
					return >=O(2^n);
		Compare ‘a’ and ‘b’ with inbulit specifications to determine the time complexity;
		return time complexity;
		}
	}
