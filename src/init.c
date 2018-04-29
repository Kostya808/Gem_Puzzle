void init (int *puzzle, unsigned int side_length)
{
	size_t cell_idx;
	size_t cell_number = side_length*side_length;
	for (cell_idx = 0; cell_idx < cell_number - 1; ++cell_idx) {
		puzzle[cell_idx] = cell_idx;
	}
	puzzle[cell_idx+1] = 0;
}
