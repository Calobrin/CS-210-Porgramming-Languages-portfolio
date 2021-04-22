# CS-210-Porgramming-Languages-portfolio

Below is the answers to questions posed to me for this assignment.

•	Summarize the project and what problem it was solving.
The project was a grocery tracking app that was displaying information of products purchased via a text document labeled “DataInput.txt”. The goal of this program was to display a menu with options to the user, to display the occurrence of each item in that data file, to be able to search for a specific item in that data file and it’s occurrences, and to display a histogram of purchased items.
Otherwise, the problem this project was solving was incorporating two separate coding languages into one program. Of which would be incorporating Python into a C++ program, and doing so correctly without errors.

•	What did you do particularly well?
I feel like my flow of the project went exceptionally well. Tackling each part of the project one part of the time. I managed to break up the work into each menu option and managed to work on it to completion which left a result of being very satisfying.
In the specifics of code I feel I did particularly well, would be validating the user input of the menu without any possible errors of accepting incorrect input.  Secondly to that would be my work on menu option #1 which I was very proud of, I was also proud of the work I did incorporating Python into my C++ for meu option #2. Including a if else section to ensure the item being searched existed, and calling the function to return the number to use in a cout statement.

•	Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
This would be the Histogram section of the project. Menu option #3 simply included several if else statements to set the frequency to a specific number of asterisks. I think a function could have done this separately, but I opted not to go this route due to concerns of time constraints.
It would make it more efficient because it does not consider any number larger than 10. If the data file had more than 10 occurrences, 11, 20, 999, it would still only display 10 asterisks instead. It does not take into account any number larger than what was provided in the text document, and if the text document were to change (and it likely would in a real world situation), this menu option would not be adequate to do what is asked of it.

•	Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
Menu option #3 was the most challenging. In a strange way too, because it was very similar to option #1, but it had to do something different to get a similar result. I had attempted to simply alter my menu option #1 to do essentially the same thing, but this proved to not be a perfect fix for the problem I was having. And even when I did find a near solution, I had not considered the issue that arose with writing to file an int instead of a string. It was actually my instructor that noted this issue and helped me resolve it, if not for this assistance I may have scrapped that code and rewrote it in a different way.

•	What skills from this project will be particularly transferable to other projects or course work?
The very first set of skills would be transferable to other projects would be to correctly implement Python into C++, which was something that caused a good deal of trouble for not only me, but many other classmates in this course. It was something new we had to do, and I feel by now we are all very proficient in configuring python correctly now.
Other skills include calling functions from python into your C++ code, I feel I have the basic gist of it now and could possibly do something similar in the future, as a lot of this work comes down to experience and practice.

•	How did you make this program maintainable, readable, and adaptable?
I made it readable by proper white spacing and indentation, as well as comments trying to explain what each portion of the code is doing so it is easy to understand and keep track of. One way it is adaptable is rewriting the file inputs and replacing the DataInput.txt file with something else.
But primarily this is readable by use of proper naming conventions and commenting. Lots of commenting.
