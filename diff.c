static int diff_rename_limit_default = 200;
static void print_line_count(FILE *file, int count)
		fprintf(file, "0,0");
		fprintf(file, "1");
		fprintf(file, "1,%d", count);
static void copy_file_with_prefix(FILE *file,
				  int prefix, const char *data, int size,
			fputs(set, file);
			putc(prefix, file);
			fputs(reset, file);
		putc(ch, file);
		fprintf(file, "%s\n\\ No newline at end of file\n", reset);
	fprintf(o->file,
		"%s--- %s%s%s\n%s+++ %s%s%s\n%s@@ -",
		metainfo, a_name.buf, name_a_tab, reset,
		metainfo, b_name.buf, name_b_tab, reset, fraginfo);
	print_line_count(o->file, lc_a);
	fprintf(o->file, " +");
	print_line_count(o->file, lc_b);
	fprintf(o->file, " @@%s\n", reset);
		copy_file_with_prefix(o->file, '-', one->data, one->size, old, reset);
		copy_file_with_prefix(o->file, '+', two->data, two->size, new, reset);
	FILE *file;
static void print_word(FILE *file, struct diff_words_buffer *buffer, int len, int color,
	fputs(diff_get_color(1, color), file);
	fwrite(ptr, len, 1, file);
	fputs(diff_get_color(1, DIFF_RESET), file);
			putc('\n', file);
			putc('\n', diff_words->file);
			print_word(diff_words->file,
				   &diff_words->minus, len, DIFF_FILE_OLD, 1);
			print_word(diff_words->file,
				   &diff_words->plus, len, DIFF_FILE_NEW, 0);
			print_word(diff_words->file,
				   &diff_words->plus, len, DIFF_PLAIN, 0);
		putc('\n', diff_words->file);
	FILE *file;
static void emit_line(FILE *file, const char *set, const char *reset, const char *line, int len)
	fputs(set, file);
	fwrite(line, len, 1, file);
	fputs(reset, file);
		emit_line(ecbdata->file, set, reset, line, len);
		emit_line(ecbdata->file, set, reset, line, ecbdata->nparents);
		    ecbdata->file, set, reset, ws);
		fprintf(ecbdata->file, "%s--- %s%s%s\n",
			meta, ecbdata->label_path[0], reset, name_a_tab);
		fprintf(ecbdata->file, "%s+++ %s%s%s\n",
			meta, ecbdata->label_path[1], reset, name_b_tab);
		emit_line(ecbdata->file,
			  diff_get_color(ecbdata->color_diff, DIFF_FRAGINFO),
			putc('\n', ecbdata->file);
		emit_line(ecbdata->file, reset, reset, line, len);
		emit_line(ecbdata->file, plain, reset, line, len);
		emit_line(ecbdata->file,
			  diff_get_color(ecbdata->color_diff, color),
static void show_name(FILE *file,
		      const char *prefix, const char *name, int len,
	fprintf(file, " %s%s%-*s%s |", set, prefix, len, name, reset);
static void show_graph(FILE *file, char ch, int cnt, const char *set, const char *reset)
	fprintf(file, "%s", set);
		putc(ch, file);
	fprintf(file, "%s", reset);
			show_name(options->file, prefix, name, len, reset, set);
			fprintf(options->file, "  Bin ");
			fprintf(options->file, "%s%d%s", del_c, deleted, reset);
			fprintf(options->file, " -> ");
			fprintf(options->file, "%s%d%s", add_c, added, reset);
			fprintf(options->file, " bytes");
			fprintf(options->file, "\n");
			show_name(options->file, prefix, name, len, reset, set);
			fprintf(options->file, "  Unmerged\n");
		show_name(options->file, prefix, name, len, reset, set);
		fprintf(options->file, "%5d ", added + deleted);
		show_graph(options->file, '+', add, add_c, reset);
		show_graph(options->file, '-', del, del_c, reset);
		fprintf(options->file, "\n");
	}
	fprintf(options->file,
	       "%s %d files changed, %d insertions(+), %d deletions(-)%s\n",
static void show_shortstats(struct diffstat_t* data, struct diff_options *options)
	fprintf(options->file, " %d files changed, %d insertions(+), %d deletions(-)\n",
			fprintf(options->file, "-\t-\t");
			fprintf(options->file,
				"%d\t%d\t", file->added, file->deleted);
				write_name_quoted(file->name, options->file,
				fputs(file->print_name, options->file);
				putc(options->line_termination, options->file);
				putc('\0', options->file);
				write_name_quoted(file->from_name, options->file, '\0');
			write_name_quoted(file->name, options->file, '\0');
struct dirstat_file {
	const char *name;
	unsigned long changed;
struct dirstat_dir {
	struct dirstat_file *files;
	int alloc, nr, percent, cumulative;
};

static long gather_dirstat(FILE *file, struct dirstat_dir *dir, unsigned long changed, const char *base, int baselen)
		struct dirstat_file *f = dir->files;
			this = gather_dirstat(file, dir, changed, f->name, newbaselen);
			this = f->changed;
				fprintf(file, "%4d.%01d%% %.*s\n", percent, permille % 10, baselen, base);
static void show_dirstat(struct diff_options *options)
	struct dirstat_dir dir;
	struct diff_queue_struct *q = &diff_queued_diff;

	dir.files = NULL;
	dir.alloc = 0;
	dir.nr = 0;
	dir.percent = options->dirstat_percent;
	dir.cumulative = options->output_format & DIFF_FORMAT_CUMULATIVE;
	for (i = 0; i < q->nr; i++) {
		struct diff_filepair *p = q->queue[i];
		const char *name;
		unsigned long copied, added, damage;

		name = p->one->path ? p->one->path : p->two->path;

		if (DIFF_FILE_VALID(p->one) && DIFF_FILE_VALID(p->two)) {
			diff_populate_filespec(p->one, 0);
			diff_populate_filespec(p->two, 0);
			diffcore_count_changes(p->one, p->two, NULL, NULL, 0,
					       &copied, &added);
			diff_free_filespec_data(p->one);
			diff_free_filespec_data(p->two);
		} else if (DIFF_FILE_VALID(p->one)) {
			diff_populate_filespec(p->one, 1);
			copied = added = 0;
			diff_free_filespec_data(p->one);
		} else if (DIFF_FILE_VALID(p->two)) {
			diff_populate_filespec(p->two, 1);
			copied = 0;
			added = p->two->size;
			diff_free_filespec_data(p->two);
		} else

		/*
		 * Original minus copied is the removed material,
		 * added is the new material.  They are both damages
		 * made to the preimage.
		 */
		damage = (p->one->size - copied) + added;

		ALLOC_GROW(dir.files, dir.nr + 1, dir.alloc);
		dir.files[dir.nr].name = name;
		dir.files[dir.nr].changed = damage;
		changed += damage;
		dir.nr++;
	gather_dirstat(options->file, &dir, changed, "", 0);
	FILE *file;
		fprintf(data->file, "%s:%d: %s.\n", data->filename, data->lineno, err);
		emit_line(data->file, set, reset, line, 1);
		    data->file, set, reset, ws);
static void emit_binary_diff_body(FILE *file, mmfile_t *one, mmfile_t *two)
		fprintf(file, "delta %lu\n", orig_size);
		fprintf(file, "literal %lu\n", two->size);
		fputs(line, file);
		fputc('\n', file);
	fprintf(file, "\n");
static void emit_binary_diff(FILE *file, mmfile_t *one, mmfile_t *two)
	fprintf(file, "GIT binary patch\n");
	emit_binary_diff_body(file, one, two);
	emit_binary_diff_body(file, two, one);
	fprintf(o->file, "%sdiff --git %s %s%s\n", set, a_one, b_two, reset);
		fprintf(o->file, "%snew file mode %06o%s\n", set, two->mode, reset);
			fprintf(o->file, "%s%s%s\n", set, xfrm_msg, reset);
		fprintf(o->file, "%sdeleted file mode %06o%s\n", set, one->mode, reset);
			fprintf(o->file, "%s%s%s\n", set, xfrm_msg, reset);
			fprintf(o->file, "%sold mode %06o%s\n", set, one->mode, reset);
			fprintf(o->file, "%snew mode %06o%s\n", set, two->mode, reset);
			fprintf(o->file, "%s%s%s\n", set, xfrm_msg, reset);
			emit_binary_diff(o->file, &mf1, &mf2);
			fprintf(o->file, "Binary files %s and %s differ\n",
				lbl[0], lbl[1]);
		ecbdata.file = o->file;
		if (DIFF_OPT_TST(o, COLOR_DIFF_WORDS)) {
			ecbdata.diff_words->file = o->file;
		}
	data.file = o->file;
		fprintf(o->file, "* Unmerged path %s\n", name);

	options->file = stdout;

	else if (!prefixcmp(arg, "--output=")) {
		options->file = fopen(arg + strlen("--output="), "w");
		options->close_file = 1;
	} else
		fprintf(opt->file, ":%06o %06o %s ", p->one->mode, p->two->mode,
			diff_unique_abbrev(p->one->sha1, opt->abbrev));
		fprintf(opt->file, "%s ", diff_unique_abbrev(p->two->sha1, opt->abbrev));
		fprintf(opt->file, "%c%03d%c", p->status, similarity_index(p),
			inter_name_termination);
		fprintf(opt->file, "%c%c", p->status, inter_name_termination);
		write_name_quoted(name_a, opt->file, inter_name_termination);
		write_name_quoted(name_b, opt->file, line_termination);
		write_name_quoted(name_a, opt->file, line_termination);
		write_name_quoted(name_a, opt->file, opt->line_termination);
static void show_file_mode_name(FILE *file, const char *newdelete, struct diff_filespec *fs)
		fprintf(file, " %s mode %06o ", newdelete, fs->mode);
		fprintf(file, " %s ", newdelete);
	write_name_quoted(fs->path, file, '\n');
static void show_mode_change(FILE *file, struct diff_filepair *p, int show_name)
		fprintf(file, " mode change %06o => %06o%c", p->one->mode, p->two->mode,
			write_name_quoted(p->two->path, file, '\n');
static void show_rename_copy(FILE *file, const char *renamecopy, struct diff_filepair *p)
	fprintf(file, " %s %s (%d%%)\n", renamecopy, names, similarity_index(p));
	show_mode_change(file, p, 0);
static void diff_summary(FILE *file, struct diff_filepair *p)
		show_file_mode_name(file, "delete", p->one);
		show_file_mode_name(file, "create", p->two);
		show_rename_copy(file, "copy", p);
		show_rename_copy(file, "rename", p);
			fputs(" rewrite ", file);
			write_name_quoted(p->two->path, file, ' ');
			fprintf(file, "(%d%%)\n", similarity_index(p));
		show_mode_change(file, p, !p->score);
	if (output_format & (DIFF_FORMAT_DIFFSTAT|DIFF_FORMAT_SHORTSTAT|DIFF_FORMAT_NUMSTAT)) {
			show_shortstats(&diffstat, options);
	if (output_format & DIFF_FORMAT_DIRSTAT)
		show_dirstat(options);
			diff_summary(options->file, q->queue[i]);
				fputs(options->stat_sep, options->file);
				putc(options->line_termination, options->file);
	if (options->close_file)
		fclose(options->file);