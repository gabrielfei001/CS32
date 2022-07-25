#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    WordCount test1;
    WordCount test2;
    test1.incrWordCount("Words");
    test1.incrWordCount("W0rds");
    test1.incrWordCount("WORDS");
    test1.incrWordCount("words");
    test1.incrWordCount("ding");
    test1.incrWordCount("d1ng");
    test1.incrWordCount("23a'32-4");
    assertEquals(test1.getNumUniqueWords(), 5, " at ", __LINE__);
    assertEquals(test1.getWordCount("words"), 3, " at ", __LINE__);
    assertEquals(test1.getWordCount("ding"), 1, " at ", __LINE__);
    assertEquals(test1.getTotalWords(), 7, " at ", __LINE__);
    assertEquals(test1.decrWordCount("words"), 2, " at ", __LINE__);
    assertEquals(test1.decrWordCount("ding"), 0, " at ", __LINE__);
    assertEquals(test1.decrWordCount("ding"), -1, " at ", __LINE__);
    assertEquals(test1.getNumUniqueWords(), 4, " at ", __LINE__);
    assertEquals(test1.getTotalWords(), 5, " at ", __LINE__);
    cout << test1.makeValidWord(".foo") << endl;
    cout << test1.makeValidWord("bar?") << endl;
    cout << test1.makeValidWord("...fum***") << endl;
    cout << test1.makeValidWord("\"quote\"") << endl;
    cout << test1.makeValidWord("isn't") << endl;
    cout << test1.makeValidWord("mother-in-law") << endl;
    cout << test1.makeValidWord("'aRT-*") << endl;
    cout << test1.makeValidWord("$-s'-#") << endl;
    cout << test1.makeValidWord("$$*-'-!") << endl;
    cout <<test1.makeValidWord("") << endl;
    assertEquals(test2.incrWordCount("foO"), 1, " at ", __LINE__);
    assertEquals(test2.incrWordCount("foo"), 2, " at ", __LINE__);
    assertEquals(test2.incrWordCount("bAr"), 1, " at ", __LINE__);
    assertEquals(test2.incrWordCount("BaR"), 2, " at ", __LINE__);
    assertEquals(test2.incrWordCount("foo#bar"), 1, " at ", __LINE__);
    assertEquals(test2.incrWordCount("foo_bar-"), 2, " at ", __LINE__);
    assertEquals(test2.incrWordCount("--$$--"), 0, " at ", __LINE__);
    assertEquals(test2.getTotalWords(), 6, " at ", __LINE__);
    assertEquals(test2.getNumUniqueWords(), 3, " at ", __LINE__);

}
