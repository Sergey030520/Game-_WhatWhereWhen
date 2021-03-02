# Game-_WhatWhereWhen
Implementation of the game " What? Where? When?"Implementation of the game " What? Where? When?".At the beginning of each turn, the players spin the top, that is, select the sector on the table that is currently playing. There are 13 such sectors in total. The sector is selected as follows: the offset (offset) relative to the current sector on the reel is entered from the keyboard. Based on this offset, a new active sector is calculated, which will play in this turn. If the dropped sector has already been played, the next non-player chooses it. At the beginning of the entire game, the arrow is set on the first sector.

As soon as one of the sectors plays, a letter with a question is taken from it — that is, it is read from the file of this sector. The question is displayed on the screen.

After the question is shown, the player is expected to answer it. The player enters this answer using standard input. What he entered is compared to the response, which is stored in the second file associated with the active sector. This file should contain only one word-the answer.

If the expert player's answer was correct, he is awarded one.
