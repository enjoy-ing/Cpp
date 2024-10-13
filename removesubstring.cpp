<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Solution</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            background-color: #f4f4f4;
            margin: 0;
            padding: 20px;
        }

        h1 {
            color: #333;
            margin-bottom: 30px;
        }

        p {
            font-size: 18px;
            color: #555;
            max-width: 800px;
            margin: 0 auto 40px auto;
        }

        .code-container {
            display: inline-block;
            text-align: left;
            margin-bottom: 20px;
            width: 100%;
            max-width: 90%;
        }

        pre {
            background-color: #272822;
            color: #f8f8f2;
            padding: 15px;
            border-radius: 5px;
            text-align: left;
            overflow: auto; /* Allows both horizontal and vertical scrolling */
            white-space: pre; /* Preserves formatting */
            max-width: 100%;  /* The code block takes the full width of the container */
        }

        .copy-btn {
            background-color: #4CAF50;
            color: white;
            border: none;
            padding: 8px 12px;
            border-radius: 3px;
            cursor: pointer;
            font-size: 14px;
            margin-bottom: 10px;
        }

        .copy-btn:hover {
            background-color: #45a049;
        }

        a {
            display: inline-block;
            margin-top: 30px;
            font-size: 16px;
            text-decoration: none;
            color: #0066cc;
        }

        a:hover {
            color: #ff6600;
        }

        /* Tooltip container */
        .tooltip {
            position: relative;
            display: inline-block;
        }

        /* Tooltip text */
        .tooltip .tooltiptext {
            visibility: hidden;
            width: 120px;
            background-color: #555;
            color: #fff;
            text-align: center;
            border-radius: 6px;
            padding: 5px 0;
            position: absolute;
            z-index: 1;
            bottom: 125%; /* Position above the button */
            left: 50%;
            margin-left: -60px;
            opacity: 0;
            transition: opacity 0.3s;
        }

        /* Tooltip arrow */
        .tooltip .tooltiptext::after {
            content: "";
            position: absolute;
            top: 100%; /* At the bottom of the tooltip */
            left: 50%;
            margin-left: -5px;
            border-width: 5px;
            border-style: solid;
            border-color: #555 transparent transparent transparent;
        }

        /* Show tooltip on button click */
        .tooltip.active .tooltiptext {
            visibility: visible;
            opacity: 1;
        }
    </style>
</head>
<body>
    <h1>Solution</h1>

    <div class="code-container">
        <button class="copy-btn tooltip" onclick="copyToClipboard()">Click to Copy
            <span class="tooltiptext" id="tooltipText">Copied!</span>
        </button>

        <pre id="codeSnippet">
#include &lt;iostream&gt;
using namespace std;
int removestr(char S[], int N){  
    int n = 0;
    for(int i = 0; i < N; i++){
        S[n++] = S[i];
        if (n > 2 && S[n-3] == '1' && S[n-2] == '0' && S[n-1] == '0')
            n -= 3;
    }
    return n;
}
int main(){
    int N;
    cin >> N;
    char S[N];
    for(int i = 0; i < N; i++) 
        cin >> S[i];
    int len = removestr(S, N);
    if (len == 0) 
        cout << -1 << endl;
    else{
        for(int i = 0; i < len; i++)
            cout << S[i];
        cout << endl;
    }
    return 0;
}
        </pre>
    </div>

    <a href="index.html">Back to Lab Solutions</a>

    <script>
        function copyToClipboard() {
            var code = document.getElementById("codeSnippet").innerText;

            var textarea = document.createElement("textarea");
            textarea.value = code;
            document.body.appendChild(textarea);

            textarea.select();
            textarea.setSelectionRange(0, 99999); // For mobile devices

            try {
                var successful = document.execCommand('copy');
                if (successful) {
                    showTooltip();
                } else {
                    alert('Unable to copy');
                }
            } catch (err) {
                alert('Oops, unable to copy');
            }

            document.body.removeChild(textarea);
        }

        function showTooltip() {
            var tooltip = document.getElementById("tooltipText");
            tooltip.style.visibility = "visible";
            tooltip.style.opacity = "1";

            setTimeout(function() {
                tooltip.style.visibility = "hidden";
                tooltip.style.opacity = "0";
            }, 2000);
        }
    </script>
</body>
</html>