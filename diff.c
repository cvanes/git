static int diff_rename_limit_default = 400;
static int diff_no_prefix;
static int diff_dirstat_permille_default = 30;
static struct diff_options default_diff_options;
static int parse_dirstat_params(struct diff_options *options, const char *params,
				struct strbuf *errmsg)
{
	const char *p = params;
	int p_len, ret = 0;

	while (*p) {
		p_len = strchrnul(p, ',') - p;
		if (!memcmp(p, "changes", p_len)) {
			DIFF_OPT_CLR(options, DIRSTAT_BY_LINE);
			DIFF_OPT_CLR(options, DIRSTAT_BY_FILE);
		} else if (!memcmp(p, "lines", p_len)) {
			DIFF_OPT_SET(options, DIRSTAT_BY_LINE);
			DIFF_OPT_CLR(options, DIRSTAT_BY_FILE);
		} else if (!memcmp(p, "files", p_len)) {
			DIFF_OPT_CLR(options, DIRSTAT_BY_LINE);
			DIFF_OPT_SET(options, DIRSTAT_BY_FILE);
		} else if (!memcmp(p, "noncumulative", p_len)) {
			DIFF_OPT_CLR(options, DIRSTAT_CUMULATIVE);
		} else if (!memcmp(p, "cumulative", p_len)) {
			DIFF_OPT_SET(options, DIRSTAT_CUMULATIVE);
		} else if (isdigit(*p)) {
			char *end;
			int permille = strtoul(p, &end, 10) * 10;
			if (*end == '.' && isdigit(*++end)) {
				/* only use first digit */
				permille += *end - '0';
				/* .. and ignore any further digits */
				while (isdigit(*++end))
					; /* nothing */
			}
			if (end - p == p_len)
				options->dirstat_permille = permille;
			else {
				strbuf_addf(errmsg, _("  Failed to parse dirstat cut-off percentage '%.*s'\n"),
					    p_len, p);
				ret++;
			}
		} else {
			strbuf_addf(errmsg, _("  Unknown dirstat parameter '%.*s'\n"),
				    p_len, p);
			ret++;
		}

		p += p_len;

		if (*p)
			p++; /* more parameters, swallow separator */
	}
	return ret;
}

	if (!strcmp(var, "diff.noprefix")) {
		diff_no_prefix = git_config_bool(var, value);
		return 0;
	}
	if (!strcmp(var, "diff.ignoresubmodules"))
		handle_ignore_submodules_arg(&default_diff_options, value);

	if (!strcmp(var, "diff.dirstat")) {
		struct strbuf errmsg = STRBUF_INIT;
		default_diff_options.dirstat_permille = diff_dirstat_permille_default;
		if (parse_dirstat_params(&default_diff_options, value, &errmsg))
			warning(_("Found errors in 'diff.dirstat' config variable:\n%s"),
				errmsg.buf);
		strbuf_release(&errmsg);
		diff_dirstat_permille_default = default_diff_options.dirstat_permille;
		return 0;
	}

	if (!prefixcmp(var, "submodule."))
		return parse_submodule_config_option(var, value);

	struct diff_options *opt;
/* like fill_mmfile, but only for size, so we can avoid retrieving blob */
static unsigned long diff_filespec_size(struct diff_filespec *one)
{
	if (!DIFF_FILE_VALID(one))
		return 0;
	diff_populate_filespec(one, 1);
	return one->size;
}

static void emit_line_0(struct diff_options *o, const char *set, const char *reset,
	FILE *file = o->file;

	if (o->output_prefix) {
		struct strbuf *msg = NULL;
		msg = o->output_prefix(o, o->output_prefix_data);
		assert(msg);
		fwrite(msg->buf, msg->len, 1, file);
	}
static void emit_line(struct diff_options *o, const char *set, const char *reset,
	emit_line_0(o, set, reset, line[0], line+1, len-1);
		emit_line_0(ecbdata->opt, set, reset, '+', line, len);
		emit_line_0(ecbdata->opt, ws, reset, '+', line, len);
		emit_line_0(ecbdata->opt, set, reset, '+', "", 0);
			      ecbdata->opt->file, set, reset, ws);
	struct strbuf msgbuf = STRBUF_INIT;
	int org_len = len;
	int i = 1;
		emit_line(ecbdata->opt, plain, reset, line, len);
	strbuf_add(&msgbuf, frag, strlen(frag));
	strbuf_add(&msgbuf, line, ep - line);
	strbuf_add(&msgbuf, reset, strlen(reset));

	/*
	 * trailing "\r\n"
	 */
	for ( ; i < 3; i++)
		if (line[len - i] == '\r' || line[len - i] == '\n')
			len--;
	if (ep != cp) {
		strbuf_add(&msgbuf, plain, strlen(plain));
		strbuf_add(&msgbuf, cp, ep - cp);
		strbuf_add(&msgbuf, reset, strlen(reset));
	}
	if (ep < line + len) {
		strbuf_add(&msgbuf, func, strlen(func));
		strbuf_add(&msgbuf, ep, line + len - ep);
		strbuf_add(&msgbuf, reset, strlen(reset));
	}

	strbuf_add(&msgbuf, line + len, org_len - len);
	emit_line(ecbdata->opt, "", "", msgbuf.buf, msgbuf.len);
	strbuf_release(&msgbuf);
			emit_line_0(ecb->opt, old, reset, '-',
		emit_line_0(ecb->opt, plain, reset, '\\',
			      struct userdiff_driver *textconv_one,
			      struct userdiff_driver *textconv_two,
	char *data_one, *data_two;
	char *line_prefix = "";
	struct strbuf *msgbuf;

	if (o && o->output_prefix) {
		msgbuf = o->output_prefix(o, o->output_prefix_data);
		line_prefix = msgbuf->buf;
	}
	size_one = fill_textconv(textconv_one, one, &data_one);
	size_two = fill_textconv(textconv_two, two, &data_two);
	ecbdata.opt = o;
		"%s%s--- %s%s%s\n%s%s+++ %s%s%s\n%s%s@@ -",
		line_prefix, metainfo, a_name.buf, name_a_tab, reset,
		line_prefix, metainfo, b_name.buf, name_b_tab, reset,
		line_prefix, fraginfo);
	if (!o->irreversible_delete)
		print_line_count(o->file, lc_a);
	else
		fprintf(o->file, "?,?");
	if (lc_a && !o->irreversible_delete)
struct diff_words_style_elem {
	const char *prefix;
	const char *suffix;
	const char *color; /* NULL; filled in by the setup code if
			    * color is enabled */
};

struct diff_words_style {
	enum diff_words_type type;
	struct diff_words_style_elem new, old, ctx;
	const char *newline;
};

static struct diff_words_style diff_words_styles[] = {
	{ DIFF_WORDS_PORCELAIN, {"+", "\n"}, {"-", "\n"}, {" ", "\n"}, "~\n" },
	{ DIFF_WORDS_PLAIN, {"{+", "+}"}, {"[-", "-]"}, {"", ""}, "\n" },
	{ DIFF_WORDS_COLOR, {"", ""}, {"", ""}, {"", ""}, "\n" }
};

	int last_minus;
	struct diff_options *opt;
	enum diff_words_type type;
	struct diff_words_style *style;
static int fn_out_diff_words_write_helper(FILE *fp,
					  struct diff_words_style_elem *st_el,
					  const char *newline,
					  size_t count, const char *buf,
					  const char *line_prefix)
{
	int print = 0;

	while (count) {
		char *p = memchr(buf, '\n', count);
		if (print)
			fputs(line_prefix, fp);
		if (p != buf) {
			if (st_el->color && fputs(st_el->color, fp) < 0)
				return -1;
			if (fputs(st_el->prefix, fp) < 0 ||
			    fwrite(buf, p ? p - buf : count, 1, fp) != 1 ||
			    fputs(st_el->suffix, fp) < 0)
				return -1;
			if (st_el->color && *st_el->color
			    && fputs(GIT_COLOR_RESET, fp) < 0)
				return -1;
		}
		if (!p)
			return 0;
		if (fputs(newline, fp) < 0)
			return -1;
		count -= p + 1 - buf;
		buf = p + 1;
		print = 1;
	}
	return 0;
}

/*
 * '--color-words' algorithm can be described as:
 *
 *   1. collect a the minus/plus lines of a diff hunk, divided into
 *      minus-lines and plus-lines;
 *
 *   2. break both minus-lines and plus-lines into words and
 *      place them into two mmfile_t with one word for each line;
 *
 *   3. use xdiff to run diff on the two mmfile_t to get the words level diff;
 *
 * And for the common parts of the both file, we output the plus side text.
 * diff_words->current_plus is used to trace the current position of the plus file
 * which printed. diff_words->last_minus is used to trace the last minus word
 * printed.
 *
 * For '--graph' to work with '--color-words', we need to output the graph prefix
 * on each line of color words output. Generally, there are two conditions on
 * which we should output the prefix.
 *
 *   1. diff_words->last_minus == 0 &&
 *      diff_words->current_plus == diff_words->plus.text.ptr
 *
 *      that is: the plus text must start as a new line, and if there is no minus
 *      word printed, a graph prefix must be printed.
 *
 *   2. diff_words->current_plus > diff_words->plus.text.ptr &&
 *      *(diff_words->current_plus - 1) == '\n'
 *
 *      that is: a graph prefix must be printed following a '\n'
 */
static int color_words_output_graph_prefix(struct diff_words_data *diff_words)
{
	if ((diff_words->last_minus == 0 &&
		diff_words->current_plus == diff_words->plus.text.ptr) ||
		(diff_words->current_plus > diff_words->plus.text.ptr &&
		*(diff_words->current_plus - 1) == '\n')) {
		return 1;
	} else {
		return 0;
	}
}

	struct diff_words_style *style = diff_words->style;
	struct diff_options *opt = diff_words->opt;
	struct strbuf *msgbuf;
	char *line_prefix = "";
	assert(opt);
	if (opt->output_prefix) {
		msgbuf = opt->output_prefix(opt, opt->output_prefix_data);
		line_prefix = msgbuf->buf;
	}

	if (color_words_output_graph_prefix(diff_words)) {
		fputs(line_prefix, diff_words->opt->file);
	}
	if (diff_words->current_plus != plus_begin) {
		fn_out_diff_words_write_helper(diff_words->opt->file,
				&style->ctx, style->newline,
				plus_begin - diff_words->current_plus,
				diff_words->current_plus, line_prefix);
		if (*(plus_begin - 1) == '\n')
			fputs(line_prefix, diff_words->opt->file);
	}
	if (minus_begin != minus_end) {
		fn_out_diff_words_write_helper(diff_words->opt->file,
				&style->old, style->newline,
				minus_end - minus_begin, minus_begin,
				line_prefix);
	}
	if (plus_begin != plus_end) {
		fn_out_diff_words_write_helper(diff_words->opt->file,
				&style->new, style->newline,
				plus_end - plus_begin, plus_begin,
				line_prefix);
	}
	diff_words->last_minus = minus_first;
	struct diff_words_style *style = diff_words->style;

	struct diff_options *opt = diff_words->opt;
	struct strbuf *msgbuf;
	char *line_prefix = "";

	assert(opt);
	if (opt->output_prefix) {
		msgbuf = opt->output_prefix(opt, opt->output_prefix_data);
		line_prefix = msgbuf->buf;
	}
		fputs(line_prefix, diff_words->opt->file);
		fn_out_diff_words_write_helper(diff_words->opt->file,
			&style->old, style->newline,
			diff_words->minus.text.size,
			diff_words->minus.text.ptr, line_prefix);
	diff_words->last_minus = 0;
	xpp.flags = 0;
		      &xpp, &xecfg);
			diff_words->plus.text.size) {
		if (color_words_output_graph_prefix(diff_words))
			fputs(line_prefix, diff_words->opt->file);
		fn_out_diff_words_write_helper(diff_words->opt->file,
			&style->ctx, style->newline,
			- diff_words->current_plus, diff_words->current_plus,
			line_prefix);
	}
		if (ecbdata->diff_words->word_regex) {
			regfree(ecbdata->diff_words->word_regex);
			free(ecbdata->diff_words->word_regex);
		}
	struct diff_options *o = ecbdata->opt;
	char *line_prefix = "";
	struct strbuf *msgbuf;

	if (o && o->output_prefix) {
		msgbuf = o->output_prefix(o, o->output_prefix_data);
		line_prefix = msgbuf->buf;
	}
		fprintf(ecbdata->opt->file, "%s", ecbdata->header->buf);
		fprintf(ecbdata->opt->file, "%s%s--- %s%s%s\n",
			line_prefix, meta, ecbdata->label_path[0], reset, name_a_tab);
		fprintf(ecbdata->opt->file, "%s%s+++ %s%s%s\n",
			line_prefix, meta, ecbdata->label_path[1], reset, name_b_tab);
			putc('\n', ecbdata->opt->file);
		emit_line(ecbdata->opt, reset, reset, line, len);
		if (ecbdata->diff_words
		    && ecbdata->diff_words->type == DIFF_WORDS_PORCELAIN)
			fputs("~\n", ecbdata->opt->file);
		if (ecbdata->diff_words->type == DIFF_WORDS_PORCELAIN) {
			emit_line(ecbdata->opt, plain, reset, line, len);
			fputs("~\n", ecbdata->opt->file);
		} else {
			/*
			 * Skip the prefix character, if any.  With
			 * diff_suppress_blank_empty, there may be
			 * none.
			 */
			if (line[0] != '\n') {
			      line++;
			      len--;
			}
			emit_line(ecbdata->opt, plain, reset, line, len);
		}
		emit_line(ecbdata->opt, color, reset, line, len);
	const char *reset, *add_c, *del_c;
	const char *line_prefix = "";
	struct strbuf *msg = NULL;
	if (options->output_prefix) {
		msg = options->output_prefix(options, options->output_prefix_data);
		line_prefix = msg->buf;
	}

			fprintf(options->file, "%s", line_prefix);
			fprintf(options->file, "%s", line_prefix);
		fprintf(options->file, "%s", line_prefix);
	fprintf(options->file, "%s", line_prefix);
	if (options->output_prefix) {
		struct strbuf *msg = NULL;
		msg = options->output_prefix(options,
				options->output_prefix_data);
		fprintf(options->file, "%s", msg->buf);
	}
		if (options->output_prefix) {
			struct strbuf *msg = NULL;
			msg = options->output_prefix(options,
					options->output_prefix_data);
			fprintf(options->file, "%s", msg->buf);
		}

	int alloc, nr, permille, cumulative;
static long gather_dirstat(struct diff_options *opt, struct dirstat_dir *dir,
		unsigned long changed, const char *base, int baselen)
	const char *line_prefix = "";
	struct strbuf *msg = NULL;

	if (opt->output_prefix) {
		msg = opt->output_prefix(opt, opt->output_prefix_data);
		line_prefix = msg->buf;
	}
			this = gather_dirstat(opt, dir, changed, f->name, newbaselen);
		if (this_dir) {
			int permille = this_dir * 1000 / changed;
			if (permille >= dir->permille) {
				fprintf(opt->file, "%s%4d.%01d%% %.*s\n", line_prefix,
					permille / 10, permille % 10, baselen, base);
	dir.permille = options->dirstat_permille;
		int content_changed;

		name = p->two->path ? p->two->path : p->one->path;

		if (p->one->sha1_valid && p->two->sha1_valid)
			content_changed = hashcmp(p->one->sha1, p->two->sha1);
		else
			content_changed = 1;

		if (!content_changed) {
			/*
			 * The SHA1 has not changed, so pre-/post-content is
			 * identical. We can therefore skip looking at the
			 * file contents altogether.
			 */
			damage = 0;
			goto found_damage;
		}
		if (DIFF_OPT_TST(options, DIRSTAT_BY_FILE)) {
			/*
			 * In --dirstat-by-file mode, we don't really need to
			 * look at the actual file contents at all.
			 * The fact that the SHA1 changed is enough for us to
			 * add this file to the list of results
			 * (with each file contributing equal damage).
			 */
			damage = 1;
			goto found_damage;
		}
		 * made to the preimage.
		 * If the resulting damage is zero, we know that
		 * diffcore_count_changes() considers the two entries to
		 * be identical, but since content_changed is true, we
		 * know that there must have been _some_ kind of change,
		 * so we force all entries to have damage > 0.
		if (!damage)
found_damage:
	gather_dirstat(options, &dir, changed, "", 0);
}

static void show_dirstat_by_line(struct diffstat_t *data, struct diff_options *options)
{
	int i;
	unsigned long changed;
	struct dirstat_dir dir;

	if (data->nr == 0)
		return;

	dir.files = NULL;
	dir.alloc = 0;
	dir.nr = 0;
	dir.permille = options->dirstat_permille;
	dir.cumulative = DIFF_OPT_TST(options, DIRSTAT_CUMULATIVE);

	changed = 0;
	for (i = 0; i < data->nr; i++) {
		struct diffstat_file *file = data->files[i];
		unsigned long damage = file->added + file->deleted;
		if (file->is_binary)
			/*
			 * binary files counts bytes, not lines. Must find some
			 * way to normalize binary bytes vs. textual lines.
			 * The following heuristic assumes that there are 64
			 * bytes per "line".
			 * This is stupid and ugly, but very cheap...
			 */
			damage = (damage + 63) / 64;
		ALLOC_GROW(dir.files, dir.nr + 1, dir.alloc);
		dir.files[dir.nr].name = file->name;
		dir.files[dir.nr].changed = damage;
		changed += damage;
		dir.nr++;
	}

	/* This can happen even with many files, if everything was renames */
	if (!changed)
		return;

	/* Show all directories with more than x% of the changes */
	qsort(dir.files, dir.nr, sizeof(dir.files[0]), dirstat_compare);
	gather_dirstat(options, &dir, changed, "", 0);
	char *line_prefix = "";
	struct strbuf *msgbuf;

	assert(data->o);
	if (data->o->output_prefix) {
		msgbuf = data->o->output_prefix(data->o,
			data->o->output_prefix_data);
		line_prefix = msgbuf->buf;
	}
				"%s%s:%d: leftover conflict marker\n",
				line_prefix, data->filename, data->lineno);
		fprintf(data->o->file, "%s%s:%d: %s.\n",
			line_prefix, data->filename, data->lineno, err);
		emit_line(data->o, set, reset, line, 1);
static void emit_binary_diff_body(FILE *file, mmfile_t *one, mmfile_t *two, char *prefix)
		fprintf(file, "%sdelta %lu\n", prefix, orig_size);
		fprintf(file, "%sliteral %lu\n", prefix, two->size);
		fprintf(file, "%s", prefix);
	fprintf(file, "%s\n", prefix);
static void emit_binary_diff(FILE *file, mmfile_t *one, mmfile_t *two, char *prefix)
	fprintf(file, "%sGIT binary patch\n", prefix);
	emit_binary_diff_body(file, one, two, prefix);
	emit_binary_diff_body(file, two, one, prefix);
	/* Use already-loaded driver */
	if (one->driver)
		return;

	if (S_ISREG(one->mode))

	/* Fallback to default settings */
struct userdiff_driver *get_textconv(struct diff_filespec *one)

	if (!one->driver->textconv)
		return NULL;

	if (one->driver->textconv_want_cache && !one->driver->textconv_cache) {
		struct notes_cache *c = xmalloc(sizeof(*c));
		struct strbuf name = STRBUF_INIT;

		strbuf_addf(&name, "textconv/%s", one->driver->name);
		notes_cache_init(c, name.buf, one->driver->textconv);
		one->driver->textconv_cache = c;
	}

	return one->driver;
			 int must_show_header,
	struct userdiff_driver *textconv_one = NULL;
	struct userdiff_driver *textconv_two = NULL;
	struct strbuf *msgbuf;
	char *line_prefix = "";

	if (o->output_prefix) {
		msgbuf = o->output_prefix(o, o->output_prefix_data);
		line_prefix = msgbuf->buf;
	}
	strbuf_addf(&header, "%s%sdiff --git %s %s%s\n", line_prefix, set, a_one, b_two, reset);
		strbuf_addf(&header, "%s%snew file mode %06o%s\n", line_prefix, set, two->mode, reset);
		if (xfrm_msg)
			strbuf_addstr(&header, xfrm_msg);
		must_show_header = 1;
		strbuf_addf(&header, "%s%sdeleted file mode %06o%s\n", line_prefix, set, one->mode, reset);
		if (xfrm_msg)
			strbuf_addstr(&header, xfrm_msg);
		must_show_header = 1;
			strbuf_addf(&header, "%s%sold mode %06o%s\n", line_prefix, set, one->mode, reset);
			strbuf_addf(&header, "%s%snew mode %06o%s\n", line_prefix, set, two->mode, reset);
			must_show_header = 1;
		if (xfrm_msg)
			strbuf_addstr(&header, xfrm_msg);
	if (o->irreversible_delete && lbl[1][0] == '/') {
		fprintf(o->file, "%s", header.buf);
		strbuf_reset(&header);
		goto free_ab_and_return;
	} else if (!DIFF_OPT_TST(o, TEXT) &&
	    ( (!textconv_one && diff_filespec_is_binary(one)) ||
	      (!textconv_two && diff_filespec_is_binary(two)) )) {
		if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
			die("unable to read files to diff");
		    !memcmp(mf1.ptr, mf2.ptr, mf1.size)) {
			if (must_show_header)
				fprintf(o->file, "%s", header.buf);
		}
			emit_binary_diff(o->file, &mf1, &mf2, line_prefix);
			fprintf(o->file, "%sBinary files %s and %s differ\n",
				line_prefix, lbl[0], lbl[1]);
	} else {
		if (!DIFF_XDL_TST(o, WHITESPACE_FLAGS) || must_show_header) {
		mf1.size = fill_textconv(textconv_one, one, &mf1.ptr);
		mf2.size = fill_textconv(textconv_two, two, &mf2.ptr);
		ecbdata.opt = o;
		xpp.flags = o->xdl_opts;
		if (o->word_diff) {
			int i;

			ecbdata.diff_words->type = o->word_diff;
			ecbdata.diff_words->opt = o;
			for (i = 0; i < ARRAY_SIZE(diff_words_styles); i++) {
				if (o->word_diff == diff_words_styles[i].type) {
					ecbdata.diff_words->style =
						&diff_words_styles[i];
					break;
				}
			}
			if (DIFF_OPT_TST(o, COLOR_DIFF)) {
				struct diff_words_style *st = ecbdata.diff_words->style;
				st->old.color = diff_get_color_opt(o, DIFF_FILE_OLD);
				st->new.color = diff_get_color_opt(o, DIFF_FILE_NEW);
				st->ctx.color = diff_get_color_opt(o, DIFF_PLAIN);
			}
			      &xpp, &xecfg);
		if (o->word_diff)

	if (diff_filespec_is_binary(one) || diff_filespec_is_binary(two)) {
		data->is_binary = 1;
		data->added = diff_filespec_size(two);
		data->deleted = diff_filespec_size(one);
	}

	else if (complete_rewrite) {
	else {

		if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
			die("unable to read files to diff");
		xpp.flags = o->xdl_opts;
			      &xpp, &xecfg);
		xpp.flags = 0;
			      &xpp, &xecfg);
			blank_at_eof = ecbdata.blank_at_eof_in_postimage;
		if (size_only) {
			if (type < 0)
				die("unable to read %s", sha1_to_hex(s->sha1));
		} else {
			if (!s->data)
				die("unable to read %s", sha1_to_hex(s->sha1));
			  struct diff_filepair *p,
			  int *must_show_header,
			  int use_color)
	const char *set = diff_get_color(use_color, DIFF_METAINFO);
	const char *reset = diff_get_color(use_color, DIFF_RESET);
	struct strbuf *msgbuf;
	char *line_prefix = "";

	*must_show_header = 1;
	if (o->output_prefix) {
		msgbuf = o->output_prefix(o, o->output_prefix_data);
		line_prefix = msgbuf->buf;
	}
		strbuf_addf(msg, "%s%ssimilarity index %d%%",
			    line_prefix, set, similarity_index(p));
		strbuf_addf(msg, "%s\n%s%scopy from ",
			    reset,  line_prefix, set);
		strbuf_addf(msg, "%s\n%s%scopy to ", reset, line_prefix, set);
		strbuf_addf(msg, "%s\n", reset);
		strbuf_addf(msg, "%s%ssimilarity index %d%%",
			    line_prefix, set, similarity_index(p));
		strbuf_addf(msg, "%s\n%s%srename from ",
			    reset, line_prefix, set);
		strbuf_addf(msg, "%s\n%s%srename to ",
			    reset, line_prefix, set);
		strbuf_addf(msg, "%s\n", reset);
			strbuf_addf(msg, "%s%sdissimilarity index %d%%%s\n",
				    line_prefix,
				    set, similarity_index(p), reset);
		*must_show_header = 0;
		strbuf_addf(msg, "%s%sindex %s..", line_prefix, set,
			    find_unique_abbrev(one->sha1, abbrev));
		strbuf_addstr(msg, find_unique_abbrev(two->sha1, abbrev));
		strbuf_addf(msg, "%s\n", reset);
	int must_show_header = 0;
	if (msg) {
		/*
		 * don't use colors when the header is intended for an
		 * external diff driver
		 */
		fill_metainfo(msg, name, other, one, two, o, p,
			      &must_show_header,
			      DIFF_OPT_TST(o, COLOR_DIFF) && !pgm);
		xfrm_msg = msg->len ? msg->buf : NULL;
	}

			     one, two, xfrm_msg, must_show_header,
			     o, complete_rewrite);
	if (*namep && **namep != '/') {
		if (**namep == '/')
			++*namep;
	}
	if (*otherp && **otherp != '/') {
		if (**otherp == '/')
			++*otherp;
	}
	memcpy(options, &default_diff_options, sizeof(*options));
	options->dirstat_permille = diff_dirstat_permille_default;
	if (diff_no_prefix) {
		options->a_prefix = options->b_prefix = "";
	} else if (!diff_mnemonic_prefix) {
static inline int short_opt(char opt, const char **argv,
			    const char **optarg)
{
	const char *arg = argv[0];
	if (arg[0] != '-' || arg[1] != opt)
		return 0;
	if (arg[2] != '\0') {
		*optarg = arg + 2;
		return 1;
	}
	if (!argv[1])
		die("Option '%c' requires a value", opt);
	*optarg = argv[1];
	return 2;
}

int parse_long_opt(const char *opt, const char **argv,
		   const char **optarg)
{
	const char *arg = argv[0];
	if (arg[0] != '-' || arg[1] != '-')
		return 0;
	arg += strlen("--");
	if (prefixcmp(arg, opt))
		return 0;
	arg += strlen(opt);
	if (*arg == '=') { /* sticked form: --option=value */
		*optarg = arg + 1;
		return 1;
	}
	if (*arg != '\0')
		return 0;
	/* separate form: --option value */
	if (!argv[1])
		die("Option '--%s' requires a value", opt);
	*optarg = argv[1];
	return 2;
}

static int stat_opt(struct diff_options *options, const char **av)
{
	const char *arg = av[0];
	char *end;
	int width = options->stat_width;
	int name_width = options->stat_name_width;
	int argcount = 1;

	arg += strlen("--stat");
	end = (char *)arg;

	switch (*arg) {
	case '-':
		if (!prefixcmp(arg, "-width")) {
			arg += strlen("-width");
			if (*arg == '=')
				width = strtoul(arg + 1, &end, 10);
			else if (!*arg && !av[1])
				die("Option '--stat-width' requires a value");
			else if (!*arg) {
				width = strtoul(av[1], &end, 10);
				argcount = 2;
			}
		} else if (!prefixcmp(arg, "-name-width")) {
			arg += strlen("-name-width");
			if (*arg == '=')
				name_width = strtoul(arg + 1, &end, 10);
			else if (!*arg && !av[1])
				die("Option '--stat-name-width' requires a value");
			else if (!*arg) {
				name_width = strtoul(av[1], &end, 10);
				argcount = 2;
			}
		}
		break;
	case '=':
		width = strtoul(arg+1, &end, 10);
		if (*end == ',')
			name_width = strtoul(end+1, &end, 10);
	}

	/* Important! This checks all the error cases! */
	if (*end)
		return 0;
	options->output_format |= DIFF_FORMAT_DIFFSTAT;
	options->stat_name_width = name_width;
	options->stat_width = width;
	return argcount;
}

static int parse_dirstat_opt(struct diff_options *options, const char *params)
{
	struct strbuf errmsg = STRBUF_INIT;
	if (parse_dirstat_params(options, params, &errmsg))
		die(_("Failed to parse --dirstat/-X option parameter:\n%s"),
		    errmsg.buf);
	strbuf_release(&errmsg);
	/*
	 * The caller knows a dirstat-related option is given from the command
	 * line; allow it to say "return this_function();"
	 */
	options->output_format |= DIFF_FORMAT_DIRSTAT;
	return 1;
}

	const char *optarg;
	int argcount;
	if (!strcmp(arg, "-p") || !strcmp(arg, "-u") || !strcmp(arg, "--patch"))
	else if (!strcmp(arg, "-X") || !strcmp(arg, "--dirstat"))
		return parse_dirstat_opt(options, "");
	else if (!prefixcmp(arg, "-X"))
		return parse_dirstat_opt(options, arg + 2);
	else if (!prefixcmp(arg, "--dirstat="))
		return parse_dirstat_opt(options, arg + 10);
	else if (!strcmp(arg, "--cumulative"))
		return parse_dirstat_opt(options, "cumulative");
	else if (!strcmp(arg, "--dirstat-by-file"))
		return parse_dirstat_opt(options, "files");
	else if (!prefixcmp(arg, "--dirstat-by-file=")) {
		parse_dirstat_opt(options, "files");
		return parse_dirstat_opt(options, arg + 18);
	else if (!prefixcmp(arg, "--stat"))
		/* --stat, --stat-width, or --stat-name-width */
		return stat_opt(options, av);
	else if (!prefixcmp(arg, "-B") || !prefixcmp(arg, "--break-rewrites=") ||
		 !strcmp(arg, "--break-rewrites")) {
			return error("invalid argument to -B: %s", arg+2);
	else if (!prefixcmp(arg, "-M") || !prefixcmp(arg, "--find-renames=") ||
		 !strcmp(arg, "--find-renames")) {
			return error("invalid argument to -M: %s", arg+2);
	else if (!strcmp(arg, "-D") || !strcmp(arg, "--irreversible-delete")) {
		options->irreversible_delete = 1;
	}
	else if (!prefixcmp(arg, "-C") || !prefixcmp(arg, "--find-copies=") ||
		 !strcmp(arg, "--find-copies")) {
			return error("invalid argument to -C: %s", arg+2);
		options->word_diff = DIFF_WORDS_COLOR;
		options->word_diff = DIFF_WORDS_COLOR;
	else if (!strcmp(arg, "--word-diff")) {
		if (options->word_diff == DIFF_WORDS_NONE)
			options->word_diff = DIFF_WORDS_PLAIN;
	}
	else if (!prefixcmp(arg, "--word-diff=")) {
		const char *type = arg + 12;
		if (!strcmp(type, "plain"))
			options->word_diff = DIFF_WORDS_PLAIN;
		else if (!strcmp(type, "color")) {
			DIFF_OPT_SET(options, COLOR_DIFF);
			options->word_diff = DIFF_WORDS_COLOR;
		}
		else if (!strcmp(type, "porcelain"))
			options->word_diff = DIFF_WORDS_PORCELAIN;
		else if (!strcmp(type, "none"))
			options->word_diff = DIFF_WORDS_NONE;
		else
			die("bad --word-diff argument: %s", type);
	}
	else if ((argcount = parse_long_opt("word-diff-regex", av, &optarg))) {
		if (options->word_diff == DIFF_WORDS_NONE)
			options->word_diff = DIFF_WORDS_PLAIN;
		options->word_regex = optarg;
		return argcount;
	}
	else if (!strcmp(arg, "--ignore-submodules")) {
		DIFF_OPT_SET(options, OVERRIDE_SUBMODULE_CONFIG);
		handle_ignore_submodules_arg(options, "all");
	} else if (!prefixcmp(arg, "--ignore-submodules=")) {
		DIFF_OPT_SET(options, OVERRIDE_SUBMODULE_CONFIG);
		handle_ignore_submodules_arg(options, arg + 20);
	} else if (!strcmp(arg, "--submodule"))
	else if ((argcount = short_opt('l', av, &optarg))) {
		options->rename_limit = strtoul(optarg, NULL, 10);
		return argcount;
	}
	else if ((argcount = short_opt('S', av, &optarg))) {
		options->pickaxe = optarg;
		options->pickaxe_opts |= DIFF_PICKAXE_KIND_S;
		return argcount;
	} else if ((argcount = short_opt('G', av, &optarg))) {
		options->pickaxe = optarg;
		options->pickaxe_opts |= DIFF_PICKAXE_KIND_G;
		return argcount;
	}
		options->pickaxe_opts |= DIFF_PICKAXE_ALL;
		options->pickaxe_opts |= DIFF_PICKAXE_REGEX;
	else if ((argcount = short_opt('O', av, &optarg))) {
		options->orderfile = optarg;
		return argcount;
	}
	else if ((argcount = parse_long_opt("diff-filter", av, &optarg))) {
		options->filter = optarg;
		return argcount;
	}
	else if ((argcount = parse_long_opt("src-prefix", av, &optarg))) {
		options->a_prefix = optarg;
		return argcount;
	}
	else if ((argcount = parse_long_opt("dst-prefix", av, &optarg))) {
		options->b_prefix = optarg;
		return argcount;
	}
	else if ((argcount = parse_long_opt("output", av, &optarg))) {
		options->file = fopen(optarg, "w");
			die_errno("Could not open '%s'", optarg);
		return argcount;
int parse_rename_score(const char **cp_p)
	if (cmd == '-') {
		/* convert the long-form arguments into short-form versions */
		if (!prefixcmp(opt, "break-rewrites")) {
			opt += strlen("break-rewrites");
			if (*opt == 0 || *opt++ == '=')
				cmd = 'B';
		} else if (!prefixcmp(opt, "find-copies")) {
			opt += strlen("find-copies");
			if (*opt == 0 || *opt++ == '=')
				cmd = 'C';
		} else if (!prefixcmp(opt, "find-renames")) {
			opt += strlen("find-renames");
			if (*opt == 0 || *opt++ == '=')
				cmd = 'M';
		}
	}
	opt1 = parse_rename_score(&opt);
			opt2 = parse_rename_score(&opt);
	if (opt->output_prefix) {
		struct strbuf *msg = NULL;
		msg = opt->output_prefix(opt, opt->output_prefix_data);
		fprintf(opt->file, "%s", msg->buf);
	}
		return; /* no useful stat for tree diffs */
		return; /* nothing to check in tree diffs */
static void show_mode_change(FILE *file, struct diff_filepair *p, int show_name,
		const char *line_prefix)
		fprintf(file, "%s mode change %06o => %06o%c", line_prefix, p->one->mode,
			p->two->mode, show_name ? ' ' : '\n');
static void show_rename_copy(FILE *file, const char *renamecopy, struct diff_filepair *p,
			const char *line_prefix)
	show_mode_change(file, p, 0, line_prefix);
static void diff_summary(struct diff_options *opt, struct diff_filepair *p)
	FILE *file = opt->file;
	char *line_prefix = "";

	if (opt->output_prefix) {
		struct strbuf *buf = opt->output_prefix(opt, opt->output_prefix_data);
		line_prefix = buf->buf;
	}

		fputs(line_prefix, file);
		fputs(line_prefix, file);
		fputs(line_prefix, file);
		show_rename_copy(file, "copy", p, line_prefix);
		fputs(line_prefix, file);
		show_rename_copy(file, "rename", p, line_prefix);
			fprintf(file, "%s rewrite ", line_prefix);
		show_mode_change(file, p, !p->score, line_prefix);
		if (diff_filespec_is_binary(p->one) ||
		    diff_filespec_is_binary(p->two)) {
			git_SHA1_Update(&ctx, sha1_to_hex(p->one->sha1), 40);
			git_SHA1_Update(&ctx, sha1_to_hex(p->two->sha1), 40);
			continue;
		}

		xpp.flags = 0;
		xecfg.flags = 0;
			      &xpp, &xecfg);
	DIFF_QUEUE_CLEAR(q);
static const char rename_limit_warning[] =
"inexact rename detection was skipped due to too many files.";

static const char degrade_cc_to_c_warning[] =
"only found copies from modified paths due to too many files.";

static const char rename_limit_advice[] =
"you may want to set your %s variable to at least "
"%d and retry the command.";

void diff_warn_rename_limit(const char *varname, int needed, int degraded_cc)
{
	if (degraded_cc)
		warning(degrade_cc_to_c_warning);
	else if (needed)
		warning(rename_limit_warning);
	else
		return;
	if (0 < needed && needed < 32767)
		warning(rename_limit_advice, varname, needed);
}

	int dirstat_by_line = 0;
	if (output_format & DIFF_FORMAT_DIRSTAT && DIFF_OPT_TST(options, DIRSTAT_BY_LINE))
		dirstat_by_line = 1;

	if (output_format & (DIFF_FORMAT_DIFFSTAT|DIFF_FORMAT_SHORTSTAT|DIFF_FORMAT_NUMSTAT) ||
	    dirstat_by_line) {
		if (output_format & DIFF_FORMAT_DIRSTAT)
			show_dirstat_by_line(&diffstat, options);
	if ((output_format & DIFF_FORMAT_DIRSTAT) && !dirstat_by_line)
		for (i = 0; i < q->nr; i++) {
			diff_summary(options, q->queue[i]);
		}
	DIFF_QUEUE_CLEAR(q);
	DIFF_QUEUE_CLEAR(&outq);
	DIFF_QUEUE_CLEAR(&outq);
	if (!options->found_follow) {
		/* See try_to_follow_renames() in tree-diff.c */
		if (options->break_opt != -1)
			diffcore_break(options->break_opt);
		if (options->detect_rename)
			diffcore_rename(options);
		if (options->break_opt != -1)
			diffcore_merge_broken();
	}
		diffcore_pickaxe(options);
	if (!options->found_follow)
		/* See try_to_follow_renames() in tree-diff.c */
		diff_resolve_rename_copy();

	options->found_follow = 0;

	diff_warn_rename_limit("diff.renamelimit",
			       opt->needed_rename_limit,
			       opt->degraded_cc_to_c);
/*
 * Shall changes to this submodule be ignored?
 *
 * Submodule changes can be configured to be ignored separately for each path,
 * but that configuration can be overridden from the command line.
 */
static int is_submodule_ignored(const char *path, struct diff_options *options)
{
	int ignored = 0;
	unsigned orig_flags = options->flags;
	if (!DIFF_OPT_TST(options, OVERRIDE_SUBMODULE_CONFIG))
		set_diffopt_flags_from_submodule_config(options, path);
	if (DIFF_OPT_TST(options, IGNORE_SUBMODULES))
		ignored = 1;
	options->flags = orig_flags;
	return ignored;
}

	if (S_ISGITLINK(mode) && is_submodule_ignored(concatpath, options))
	if (S_ISGITLINK(old_mode) && S_ISGITLINK(new_mode) &&
	    is_submodule_ignored(concatpath, options))
struct diff_filepair *diff_unmerge(struct diff_options *options, const char *path)
	struct diff_filepair *pair;
		return NULL;
	pair = diff_queue(&diff_queued_diff, one, two);
	pair->is_unmerged = 1;
	return pair;

size_t fill_textconv(struct userdiff_driver *driver,
		     struct diff_filespec *df,
		     char **outbuf)
{
	size_t size;

	if (!driver || !driver->textconv) {
		if (!DIFF_FILE_VALID(df)) {
			*outbuf = "";
			return 0;
		}
		if (diff_populate_filespec(df, 0))
			die("unable to read files to diff");
		*outbuf = df->data;
		return df->size;
	}

	if (driver->textconv_cache && df->sha1_valid) {
		*outbuf = notes_cache_get(driver->textconv_cache, df->sha1,
					  &size);
		if (*outbuf)
			return size;
	}

	*outbuf = run_textconv(driver->textconv, df, &size);
	if (!*outbuf)
		die("unable to read files to diff");

	if (driver->textconv_cache && df->sha1_valid) {
		/* ignore errors, as we might be in a readonly repository */
		notes_cache_put(driver->textconv_cache, df->sha1, *outbuf,
				size);
		/*
		 * we could save up changes and flush them all at the end,
		 * but we would need an extra call after all diffing is done.
		 * Since generating a cache entry is the slow path anyway,
		 * this extra overhead probably isn't a big deal.
		 */
		notes_cache_write(driver->textconv_cache);
	}

	return size;
}