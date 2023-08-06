#My adventure into the C programming language.

While looking through the net, I came across a youtube video Harverd's CS50. It's about computer science, an introduction. I got to the algorithm and decided to try a C program. I used what I learned in the video and some online searches and came up with my first C program. It's not a hello world program. It's an implementation of Gronsfeld cipher.

- `The Gronsfeld cipher`
Is a polyalphabetic substitution cipher, very similar to the Vigenère cipher. It was invented around 1744 by the Earl of Gronsfeld, José de Bronckhorst. A Gronsfeld cipher works like a series of Caesar ciphers. The secret key determines how many places each letter of the alphabet should be shifted. For example, if the secret key is 1234, the shift will be 1, 2, 3, 4, 1, 2, 3, 4, etc. The shift is done for each input letter of the message to be encrypted. The Gronsfeld cipher is vulnerable to letter frequency analysis, just like the Vigenère cipher. It has more limited key strength than Vigenère cipher, because the shift was limited to numbers between 0-9 for the original process. so unless the key is long it can be cracked by brute force methods.

- NOTE: This implementation, the key limit is from 1-13, 13 being half of 26. Also there isn't a limit on how many keys one can have. The algorithm works more like how a human would use the the cipher.

- Take a letter from the message. 
- Look the letter up in the alphabet. 
- Use the codeset letter that corresponds to the alphabet position.
