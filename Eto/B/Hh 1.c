// Homework 1
void sb_init(stringBuilder* sb)
{

}

void sb_addStr(stringBuilder* sb, const char*);

void sb_addint(stringBuilder* sb, int n);

void sb_addLine(stringBuilder* sb);

size_t sb_length(const stringBuilder* sb);

const char* sb_getStr(const stringBuilder* sb); // returns a ptr to the char that the struct has

void sb_release(stringBuilder* sb);

int main()
{
    typedef sb = stringBuilder;
    sb x;
    sb_init(&x);

    for(size_t i = 0; i < 1000; i++)
    {
        for(size_t j = 0; j < 1000; j++)
        {
            sb_addStr(&x, "(");
            sb_addint(&x, i);
            sb_addStr(&x, ":");
            sb_addint(&x, j);
            sb_addStr(&x, ")");
        }
        sb_addLine(&x);
    }

    puts(sb_getStr(%x));
    
    sb_release(&x);
}
