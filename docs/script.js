
const form = document.getElementById("alignment-form");
const sequence1Input = document.getElementById("sequence1");
const sequence2Input = document.getElementById("sequence2");
const sampleButton = document.getElementById("sample-button");
const message = document.getElementById("message");
const results = document.getElementById("results");

function findLCS(first, second) {
    const m = first.length;
    const n = second.length;

    const dp = Array.from(
        { length: m + 1 },
        () => Array(n + 1).fill(0)
    );

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (first[i - 1] === second[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    let i = m;
    let j = n;
    let lcs = [];

    while (i > 0 && j > 0) {
        if (first[i - 1] === second[j - 1]) {
            lcs.push(first[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs.reverse().join("");
}

form.addEventListener("submit", function (event) {
    event.preventDefault();

    message.textContent = "";
    results.hidden = true;

    const first = sequence1Input.value.trim().toUpperCase();
    const second = sequence2Input.value.trim().toUpperCase();
    const validDNA = /^[ATGC]+$/;

    if (!validDNA.test(first) || !validDNA.test(second)) {
        message.textContent =
            "Please enter non-empty DNA sequences containing only A, T, G and C.";
        return;
    }

    const lcs = findLCS(first, second);
    const similarity =
        (lcs.length / Math.max(first.length, second.length)) * 100;

    document.getElementById("lcs-result").textContent = lcs || "No common bases";
    document.getElementById("length-result").textContent = lcs.length;
    document.getElementById("similarity-result").textContent =
        similarity.toFixed(4) + "%";

    results.hidden = false;
});

sampleButton.addEventListener("click", function () {
    sequence1Input.value = "AGGTAC";
    sequence2Input.value = "GGTACC";
    message.textContent = "";
    form.requestSubmit();
});

form.addEventListener("reset", function () {
    message.textContent = "";
    results.hidden = true;
});
