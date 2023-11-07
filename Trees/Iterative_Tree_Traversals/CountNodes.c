/*• Traverse the tree in any of the 3 techniques and every
time a node is visited, count is incremented.*/
void count_nodes( Nodeptr root)
{
static int count = 0;
if(root!=NULL)
{
count_nodes(root→llink);
count++;
count_nodes(root→rlink);
}
return count;
}
//Finding height of a binary tree
https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbDJRQkIzWm9SVU9pZS10TzZyM2ZEOVFfbE96Z3xBQ3Jtc0tuYTVFazU5MmdyMG81LU53cXBJbTJibG45Q1ZPcWgyNzZ2NjJ5dzNSZW9PbmlrVGw3SjJzdUxLaW1xM095WUQ3WWprbkpTVUdFRm9ZbmNIMVRSNG1QRThYRzJxMjA4emh2MHZiTmhYeTNzd3l6amVlZw&q=http%3A%2F%2Fbit.ly%2F2N2TAC5&v=Ubfgi4NoTPk