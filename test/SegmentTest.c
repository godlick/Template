dummy_function (void)
{
	unsigned char *ptr = 0x00;
	*ptr = 0x00;
}

int main (void)
{
	dummy_function ();
        return 0;
}
