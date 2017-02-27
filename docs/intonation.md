[Back](docindex.html)

------------------------------------------------------------------------

INTONATION
----------

------------------------------------------------------------------------

In eSpeak's standard intonation model, a "tune" is applied to each
clause depending on its punctuation. Other intonation models may be used
for some languages, such as tone languages.

Named tunes are defined in the text file: **`phsource/intonation`**.
This file must be compiled for use by eSpeak by using the espeakedit
program, using the menu option:
**`Compile -> Compile intonation data`**.

### Clauses

The tunes which are used for a language can be specified by using a
**`tunes`** statement in a voice file in **`espeak-data/voices`**. eg:

`tunes   s1  c1   q1   e1`

It's parameters are four tune names which are used for clauses which end
in:

1.  Full-stop.
2.  Comma.
3.  Question mark.
4.  Exclamation mark.

A clause consists of the following parts:

-   Pre-head.\
    These are any unstressed syllables before the first
    stressed syllable.
-   Head.\
    This is the part from the first stressed syllable up to the last
    syllable before the nucleus.
-   Nucleus.\
    This is stressed syllable which is the focus of the clause. eSpeak
    chooses the last stressed syllable of the clause.
-   Tail.\
    These are the syllables after the nucleus.

### Tune definitions

Here is an example tune definition from the file
**`phsource/intonation`**.

    tune s1
    prehead   46 57
    headenv   fall 16
    head       4 80 55 -8 -5
    headextend 0 63 38 13 0
    nucleus  fall 70 18 24 12
    nucleus0 fall 64 8
    endtune

It contains:

**tune** &lt;tune name&gt;

Starts the definition of a tune. The **`tune name`** can be used in a
**`tunes`** statements in voice files.

**endtune** &lt;tune name&gt;

Ends the definition of a tune.

**prehead** &lt;start pitch&gt; &lt;end pitch&gt;

Gives the pitch path for any series of unstressed syllables before the
first stressed syllable.

**headenv** &lt;envelope&gt; &lt;height&gt;

Gives the pitch envelope which is used for stressed syllables in the
head (before the nucleus), including **`onset`** and **`headlast`**
syllables if these are specified. **`height`** gives a pitch range for
the envelope.

**head** &lt;steps&gt; &lt;start pitch&gt; &lt;end pitch&gt;
&lt;unstressed start&gt; &lt;unstressed end&gt;

**`start pitch`** and **`end pitch`** give a pitch path for the stressed
syllables of the head. **`steps`** is the maximum number of stressed
syllables for which this applies. If there are additional stressed
syllables, then the **`headextend`** statement is used for them.

**`unstressed start`** and **`unstressed end`** give a pitch path for
unstressed syllables between two stressed syllables. Their values are
relative to the pitch of the previous stressed syllable. Values are
usually negative, meaning that the unstressed syllables have lower pitch
than the previous stressed syllable.

**headextend** &lt;percentage list&gt;

If the head contains more stressed syllables than is specified by
**`steps`**, then **`percentage list`** is used. It contains up to 8
numbers which are used repeatedly for the additional stressed syllables.
A value of 0 corresponds to the lower the **`start pitch`** and
**`end pitch`** values of the **`head`** statement. 100 corresponds to
the higher value. Negative values and values greater than 100 are
allowed.

**nucleus** &lt;envelope&gt; &lt;top pitch&gt; &lt;bottom pitch&gt;
&lt;tail start&gt; &lt;tail end&gt;

This gives the pitch envelope and pitch range of the last stressed
syllable of the clause. **`tail start`** and **`tail end`** give a pitch
path for the unstressed syllables which are after the last stressed
syllable.

**nucleus0** &lt;envelope&gt; &lt;top pitch&gt; &lt;bottom pitch&gt;

This is used instead of **`nucleus`** if there are no unstressed
syllables after the last stressed syllable. In this case, the pitch
changes of the nucleus and the tail and both included in the nucleus.

The following attributes may also be included:

**onset** &lt;pitch&gt; &lt;unstressed start&gt; &lt;unstressed end&gt;

This specifies the pitch for the first stressed syllable of the head. If
the **`onset`** statement is present, then the **`head`** statement used
for the stressed syllables after the first.

**headlast** &lt;pitch&gt; &lt;unstressed start&gt; &lt;unstressed
end&gt;

This specifies the pitch for the last stressed syllable of the head
(i.e. the stressed syllable before the nucleus).