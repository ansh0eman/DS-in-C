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
