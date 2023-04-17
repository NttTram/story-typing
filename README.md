# story-typing
Practice typing through a story

Brain dump then clean it up:

## Functions

### Typing using keyboard
- user input through keys press down.
- user must type out the given sentence/letter
- current letter will be in light grey (transparent). 
- Correctly typed letters are in black else it's red.
- Will have "typed_text" vs "current_text" vs "og_text"
- change scene/text if "typed_text" == "og_text"
- Variables: sentences, sentence, letter...
- text alignment: There is a textbox with sentences to type.
- if text horizontally out then next line down.
- if vertically out then clear box and back to the top.

variables/keys: 
- typed_text
- current_text/current_sentence
- og_text/sentence

### Sentence/text
- From external text file (.txt, .json, etc)
- Functions to add, edit and delete text.
- Each text will be coded for precise ordering using ID.

variables/keys:
- generate id? or manually add images/sounds/animations with known id.
- add: add will add text to current file whereever you want. 
- edit: change text/sentence for error checking.
- delete: delete and restore/shift id?



### Images/sounds/animations
- images/animation is attached to certain text.
- will appear when that text appear.
- this includes sounds too.


Need a system to modify changes easily even when i haven't use for a long time. Similar to a story engine (expansion/advance)