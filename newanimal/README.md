# newanimal

REST api to create new wiki farm animals for dokuwiki

## Building

  * ``git submodule init``

    Pulls down the submodules (googletest and jsoncpp).

  * Create a parallel folder ``newanimal-build``

  * Change to that folder.

  * ``cmake ../newanimal``

  * make

    * To build just the unit tests, ``make newanimal-test``

    * To run the full tests, ``make test``, which will build and run the unit
      test suite.
