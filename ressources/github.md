# Git for Two: Our Workflow

How we work together on this repo without overwriting each other's work.

The idea in one sentence: **`main` always works, each of us codes on our own branch, and code only reaches `main` through a pull request (PR) on GitHub.**

---

## Key ideas first

Before the commands, four words that everything else builds on:

- **Repository (repo):** the project folder plus its full history. There is a copy on GitHub (the *remote*, called `origin`) and a copy on each of our computers (the *local* repo).
- **Commit:** a saved snapshot of the project at one moment, with a message saying what changed. Commits only exist on your machine until you *push* them.
- **Branch:** a movable label pointing at a line of commits. Working on your own branch means your commits don't touch anyone else's until you decide to merge.
- **Staging area:** a waiting room between your edited files and a commit. You choose which changes go into the next commit by staging them.

---

## 1. One-time setup

One of us creates the repo on GitHub, then adds the other under **Settings → Collaborators** so both can push.

Then **both of us** run:

```bash
git clone git@github.com:<owner>/<repo>.git
```
Downloads the GitHub repo to your computer: all files, all branches, all history. It creates a folder named after the repo and automatically remembers the GitHub address under the name `origin`.

```bash
cd <repo>
```
Moves your terminal into the project folder. Git commands only work inside a repo.

```bash
git config pull.rebase true
```
Changes how `git pull` behaves in this repo. Normally, pulling creates an extra "merge commit" whenever both sides have new commits. With this setting, Git instead puts your local commits back on top of the newly downloaded ones, so history stays a single clean line.

**Recommended:** on GitHub, go to **Settings → Branches** and add a protection rule for `main`. This blocks direct pushes to `main`, so everything has to go through a PR and nobody breaks it by accident.

**Also on day one:** create a `.gitignore` file (see section 6).

---

## 2. The daily loop (once per task)

### Start from an up-to-date `main`

```bash
git switch main
```
Moves you onto the `main` branch. Your files change to match what `main` contains.

```bash
git pull
```
Two steps in one: it **fetches** (downloads new commits from GitHub) and then **integrates** them into your current branch. After this, your local `main` matches GitHub's `main`.

### Create a branch for your task

```bash
git switch -c feat/parser
```
Creates a new branch called `feat/parser` starting from where you are now (the fresh `main`), and switches to it. `-c` means "create". From here on, your commits go on this branch only.

Naming convention we use: `feat/<thing>` for new features, `fix/<thing>` for bug fixes.

### Work and commit

```bash
git status
```
Shows the current state: which branch you're on, which files changed, which are staged for the next commit, and which are untracked (new files Git isn't following yet). It changes nothing, so run it as often as you like.

```bash
git add src/parser.c
```
Puts the current changes of `src/parser.c` into the staging area. Only staged changes go into the next commit. `git add .` stages everything in the current folder; be careful with it, since it can grab files you didn't mean to include.

```bash
git diff --staged
```
Shows exactly what you're about to commit, line by line. Without `--staged`, `git diff` shows changes you have **not** staged yet.

```bash
git commit -m "parser: handle quoted strings"
```
Takes everything in the staging area and saves it as a new commit on your current branch, with that message. This is **local only**: nobody else can see it yet.

Commit small and often. One commit = one logical change.

### Share your branch

```bash
git push -u origin feat/parser
```
Uploads your branch and its commits to GitHub. `-u` ("upstream") links your local branch to the GitHub one, so next time on this branch a plain `git push` or `git pull` knows where to go.

### Open a pull request

On GitHub, a banner offers **"Compare & pull request"**. Open the PR, describe what you did, and ask your partner to review.

The reviewer reads the changes, comments or approves, and then the PR is merged into `main`. Delete the branch afterwards (GitHub shows a button).

Then clean up locally:

```bash
git switch main
git pull
git branch -d feat/parser
```
The last command deletes your local copy of the branch. `-d` refuses if the branch hasn't been merged, which protects you from losing work.

---

## 3. Staying in sync while you work

While you're on your branch, your partner merges something into `main`. Bring those changes into your branch early, before the gap grows:

```bash
git switch main
git pull
git switch feat/parser
git rebase main
```
`git rebase main` takes the commits you made on your branch, temporarily sets them aside, moves your branch to the tip of the updated `main`, and then replays your commits one by one on top. The result looks as if you had started your branch from today's `main`.

Because rebase rewrites your branch's commits, if you had **already pushed** the branch, GitHub's copy no longer matches yours. Update it with:

```bash
git push --force-with-lease
```
Overwrites the branch on GitHub with your local version, **but only if** nobody else pushed to it in the meantime. If someone did, it refuses instead of destroying their work. Plain `--force` has no such check; don't use it.

> ⚠️ **Never force-push `main`.** Only force-push branches that are yours alone.

**Alternative:** `git merge main` (instead of `git rebase main`) brings in the same changes by creating one extra "merge commit" on your branch. It never rewrites history, so no force-push is needed. It's a fine choice while you're getting comfortable; the history is just less tidy.

---

## 4. Handling conflicts

A **conflict** happens when we both changed the same lines of the same file. Git can't guess which version is right, so it stops and asks you.

Git marks the conflicting part inside the file:

```
<<<<<<< HEAD
the version on the branch you're putting changes onto
=======
the version coming in
>>>>>>> your commit
```

To resolve:

1. Open the file and decide what the final code should be. It might be one side, the other, or a combination. VS Code / VSCodium show **Accept Current / Accept Incoming / Accept Both** buttons above each conflict.
2. Delete all the `<<<<<<<`, `=======`, `>>>>>>>` marker lines.
3. Build and test that it still works.

Then tell Git it's resolved:

```bash
git add src/parser.c
```
Marks the conflict in that file as resolved.

```bash
git rebase --continue
```
Continues replaying your remaining commits. (If you were doing a merge instead, run `git commit` to finish it.)

Changed your mind mid-way?

```bash
git rebase --abort
```
Cancels the whole rebase and puts your branch back exactly as it was before you started. (`git merge --abort` does the same for a merge.)

**Prevention beats cure:** agree on interfaces first and each own different files. Conflicts then become rare.

---

## 5. Undoing things safely

```bash
git restore src/parser.c
```
Throws away your **uncommitted** changes to that file, putting it back to how it was at the last commit. This can't be undone, so check first with `git diff`.

```bash
git restore --staged src/parser.c
```
Removes the file from the staging area but **keeps** your edits in the file. Use this when you `git add`-ed something by mistake.

```bash
git commit --amend
```
Replaces your last commit with a new one that includes whatever is currently staged, and lets you edit the message. Only do this on commits you **haven't pushed** yet (otherwise you'll need a force-push).

```bash
git revert <commit-hash>
```
Creates a **new** commit that does the exact opposite of the given commit. History is kept and nothing is rewritten, so this is the safe way to undo something already pushed or merged. Find the hash with `git log --oneline`.

```bash
git log --oneline --graph --all
```
Shows the history compactly: one line per commit, with a drawing of how branches split and join. Changes nothing.

> ⚠️ Avoid `git reset --hard` on anything shared. It moves your branch backwards and deletes uncommitted work without asking.

---

## 6. `.gitignore`

A file named `.gitignore` at the root of the repo lists files Git should never track. Create it on day one:

```gitignore
# Compiled objects and binaries
*.o
*.a
a.out
<program-name>

# Editor and OS files
.vscode/
.DS_Store
```

Build output changes every time either of us compiles, so tracking it would create constant, pointless conflicts.

---

## 7. Our rules

- **One branch = one task.** Keep branches short-lived: a day or two, not a week.
- **Pull before you start, push before you stop.** Unpushed work is invisible to your partner.
- **Small commits, clear messages.** `"lexer: fix off-by-one in token split"`, not `"fix"`.
- **Check before committing:** `git status` and `git diff --staged`.
- **Never commit to `main` directly.** Everything goes through a PR.
- **Never force-push `main`.**

---

## 8. Submitting to 42

Evaluations read the 42 Git repo from the intra, not GitHub. We collaborate on GitHub and push the finished `main` to the 42 repo as a second remote.

```bash
git remote add vog <url-from-the-intra>
```
Adds a second remote address under the name `vog`. Your repo now knows about two places: `origin` (GitHub) and `vog` (42). Only needed once.

```bash
git remote -v
```
Lists all remotes and their addresses, to check that both are set.

```bash
git switch main
git pull
git push vog main
```
Uploads your up-to-date `main` to the 42 repo. Only do this once `main` is clean, compiles and passes norminette, and make sure no ignored or extra files are required for the evaluation.

---

## Cheat sheet

| Command | What it does |
|---|---|
| `git clone <url>` | Download a repo from GitHub |
| `git status` | Show branch, changed and staged files |
| `git switch <branch>` | Move to an existing branch |
| `git switch -c <branch>` | Create a new branch and move to it |
| `git pull` | Download new commits and integrate them |
| `git add <file>` | Stage changes for the next commit |
| `git diff` / `git diff --staged` | Show unstaged / staged changes |
| `git commit -m "msg"` | Save staged changes as a commit (local) |
| `git push` | Upload your commits to GitHub |
| `git rebase main` | Replay your branch on top of `main` |
| `git push --force-with-lease` | Safely overwrite your own branch after a rebase |
| `git restore <file>` | Discard uncommitted changes to a file |
| `git revert <hash>` | Undo a pushed commit with a new commit |
| `git log --oneline --graph --all` | View history |
| `git branch -d <branch>` | Delete a merged local branch |

---

## First-day exercise (10 minutes)

1. Both of us create a branch from `main`.
2. Both edit **the same line** of a test file and commit.
3. Both push and open a PR.
4. Merge the first PR, then rebase the second branch onto `main`, resolve the conflict together, and merge it.

After doing this once, real conflicts stop being scary.