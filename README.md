# PageRank

<h2> Description </h2>
This is an academic project implementing the PageRank algorithm and one more
with the ZAP factor. The "examples" folder contains some graph descriptions
respecting the Standford format (see http://snap.stanford.edu/data/index.html).
The implementing algorithms are tested on these graph and the main purpose of
this little project is to simulate an search (like the google, bing, yahoo
search) but the results is only nodes numbers. 

<h2> Compilation </h2>

In a terminal, enter the command <strong>make</strong>.

The project is compiled with the new standard of C++ in order to test the
functionalities provided by the standard.

<h2> Execution </h2>

The compilation will create the <strong>search_word</strong> executable and you
can try with this way :	

$ <i> ./search_words examples/Amazon.txt </i> 

By default, the number of printed results is 10 by you can change this number

with this way :

$ <i> ./search_words examples/Amazon.txt 100 </i> 

It will show the first 100 results until 10. 







