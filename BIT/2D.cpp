for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && pts[j] == pts[i]) j++;
        int count = j - i;
        int base_val = BIT.query(pts[i].second);
        int controlled = base_val + (count - 1); 
        total_ans += controlled * count; 
        BIT.update(pts[i].second, count);
        i = j;}