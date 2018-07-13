BEGIN       {
              cur_block="-1";
              delimiter="  ";
            }
/^[^\ ]/    {
              if (block == -1)
                print $0;
              cur_block+=1;
            }
            {
              if (cur_block == block)
                print $0;
            }
