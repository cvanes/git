static char *grab_blob(const unsigned char *sha1, unsigned int mode, unsigned long *size)
			 int num_parent, int result_deleted)
	xdemitcb_t ecb;
	parent_file.ptr = grab_blob(parent, mode, &sz);
	xpp.flags = XDF_NEED_MINIMAL;
		      &xpp, &xecfg, &ecb);
			    int dense, struct rev_info *rev)
	int working_tree_file = is_null_sha1(elem->sha1);
	int abbrev = DIFF_OPT_TST(opt, FULL_INDEX) ? 40 : DEFAULT_ABBREV;
	const char *a_prefix, *b_prefix;
	a_prefix = opt->a_prefix ? opt->a_prefix : "a/";
	b_prefix = opt->b_prefix ? opt->b_prefix : "b/";
		result = grab_blob(elem->sha1, elem->mode, &result_size);
				result = grab_blob(elem->sha1, elem->mode, &result_size);
				result = grab_blob(sha1, elem->mode, &result_size);
				     cnt, i, num_parent, result_deleted);
		if (elem->parent[i].mode != elem->mode)
			mode_differs = 1;
		const char *abb;
		int use_color = DIFF_OPT_TST(opt, COLOR_DIFF);
		const char *c_meta = diff_get_color(use_color, DIFF_METAINFO);
		const char *c_reset = diff_get_color(use_color, DIFF_RESET);
		int added = 0;
		int deleted = 0;

		if (rev->loginfo && !rev->no_commit_id)
			show_log(rev);
		dump_quoted_path(dense ? "diff --cc " : "diff --combined ",
				 "", elem->path, c_meta, c_reset);
		printf("%sindex ", c_meta);
		for (i = 0; i < num_parent; i++) {
			abb = find_unique_abbrev(elem->parent[i].sha1,
						 abbrev);
			printf("%s%s", i ? "," : "", abb);
		}
		abb = find_unique_abbrev(elem->sha1, abbrev);
		printf("..%s%s\n", abb, c_reset);

		if (mode_differs) {
			deleted = !elem->mode;

			/* We say it was added if nobody had it */
			added = !deleted;
			for (i = 0; added && i < num_parent; i++)
				if (elem->parent[i].status !=
				    DIFF_STATUS_ADDED)
					added = 0;
			if (added)
				printf("%snew file mode %06o",
				       c_meta, elem->mode);
			else {
				if (deleted)
					printf("%sdeleted file ", c_meta);
				printf("mode ");
				for (i = 0; i < num_parent; i++) {
					printf("%s%06o", i ? "," : "",
					       elem->parent[i].mode);
				}
				if (elem->mode)
					printf("..%06o", elem->mode);
			}
			printf("%s\n", c_reset);
		}
		if (added)
			dump_quoted_path("--- ", "", "/dev/null",
					 c_meta, c_reset);
		else
			dump_quoted_path("--- ", a_prefix, elem->path,
					 c_meta, c_reset);
		if (deleted)
			dump_quoted_path("+++ ", "", "/dev/null",
					 c_meta, c_reset);
		else
			dump_quoted_path("+++ ", b_prefix, elem->path,
					 c_meta, c_reset);
		show_patch_diff(p, num_parent, dense, rev);
							rev);