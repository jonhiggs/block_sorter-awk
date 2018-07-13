BEGIN       {
              cur_block="-1";
              delimiter="  ";
            }
/^[^\ ]/    {
              cur_block+=1;
            }
            {
              if (cur_block == block)
                print $0;
            }
