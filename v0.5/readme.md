#v0.5

The major changes to this version are these:

>palette is now handled as an RGBA array

>to make things a little more logically structured,
  Voraldo has been split up into a number of classes

The top level Voraldo class now only holds block dimensions, number of cells,
 accessor/mutator functions for each class, the palette, and of course, the
 actual 1D data array.

To perform all the same functions that were available before, we are now looking
 at two different classes, Voraldo_IO and Voraldo_Draw, which have been designed
 in an interesting way. Each of these classes holds a pointer to the parent
 Voraldo object - that is to say, they have access to the data.

Voraldo_IO handles the load, save, and display functions, of which the save and
 display functions only access the data, while load will deallocate the block
 and allocate a new one that matches the dimensions in the saved file.

Voraldo_Draw handles all drawing and masking functions, including init_block.

This structure, it seems to me, is extensible in the sense that other classes
 can be added in the same sort of position occupied by the Voraldo_IO and
 Voraldo_Draw, which will allow bidirectional access. By this I mean that
 Voraldo can call any of the functions in Voraldo_IO and Voraldo_Draw and those
 classes can, in turn, do their business by referring back to the data held in
 the top level Voraldo class.

The structure is somewhat circular in nature, which led to the need for a
 forward declaration of the Voraldo class, so that Voraldo_IO and Voraldo_Draw
 could have pointers the parent object.


The current structure of this program is shown in the diagram below:

![diagram](https://raw.githubusercontent.com/0xBAMA/V0.5/master/voraldo%20with%20comments.png)


also, the color palette is included here:
![palette](https://raw.githubusercontent.com/0xBAMA/V0.5/master/colors.png)
