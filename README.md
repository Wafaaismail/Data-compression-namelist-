# Data-compression-namelist-
Introduction 
	RLE bit level with name list .
Algorithm 
	compression : 
		convert each character to its ascii code then this ascii to binary form .
		loop on this stream and count zeros between each successive ones and save them in a container .
		convert the saved numbers into binary form each one 4 digit .
	decompression : 
		divide the stream of zeros ones into groups each one is 4 digits and converted to decimal then put them in a queue (each group is considered number of zeros between 2 successive ones in binary form ) .
		if there is a group after conversion to decimal = 15  then you should add the successive group to this group .
		Make up the original stream of bits by putting number of zeros = the first element in the queue then put 1 then number of zeros = the second element … etc 
		divide the new stream into groups each one 8 digit ( each group now considered ascii code for an character ) 
		convert each group to decimal then cast it to character .

Conclusion  
	it depends on the input … our input ratio was .82
