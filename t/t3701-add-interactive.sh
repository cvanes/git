. "$TEST_DIRECTORY"/lib-prereq-FILEMODE.sh
test_expect_success PERL 'setup (initial)' '
test_expect_success PERL 'status works (initial)' '

test_expect_success PERL 'setup expected' '
'

test_expect_success PERL 'diff works (initial)' '
test_expect_success PERL 'revert works (initial)' '
test_expect_success PERL 'setup (commit)' '
test_expect_success PERL 'status works (commit)' '

test_expect_success PERL 'setup expected' '
'

test_expect_success PERL 'diff works (commit)' '
test_expect_success PERL 'revert works (commit)' '

test_expect_success PERL 'setup expected' '
'

test_expect_success PERL 'setup fake editor' '
	>fake_editor.sh &&
	chmod a+x fake_editor.sh &&
	test_set_editor "$(pwd)/fake_editor.sh"
'

test_expect_success PERL 'dummy edit works' '
test_expect_success PERL 'setup patch' '
-does not
'

test_expect_success PERL 'setup fake editor' '
	echo "#!$SHELL_PATH" >fake_editor.sh &&
	cat >>fake_editor.sh <<\EOF &&
	chmod a+x fake_editor.sh &&
	test_set_editor "$(pwd)/fake_editor.sh"
'

test_expect_success PERL 'bad edit rejected' '
test_expect_success PERL 'setup patch' '
'

test_expect_success PERL 'garbage edit rejected' '
test_expect_success PERL 'setup patch' '
'

test_expect_success PERL 'setup expected' '