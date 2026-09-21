let heart_rate = 0.0;
let spo2 = 0.0;
let entry_log = "";
let total_entry = 0;
let total_hr = 0.0;
let total_spo2 = 0.0;

function avg_heart_rate(total_hr , total_entry){
    return total_hr/ total_entry;
}

function avg_spo2(total_spo2, total_entry){
    return total_spo2/ total_entry;
}

function calculate_risk_score(hr, spo2){
    return (100-spo2) * 2 + Math.abs(hr - 80) * 0.5;
}

document.getElementById("save-reading").addEventListener("click", function () {

    heart_rate = Number(document.getElementById("heart-rate").value);
    spo2 = Number(document.getElementById("spo2").value);

    entry_log += `Heart Rate = ${heart_rate} and  Oxygen Saturation = ${spo2} Added.\n`;
    total_entry++;
    total_hr += heart_rate;
    total_spo2 += spo2;

    document.getElementById("show-result").innerHTML = `${entry_log} <br> <br>`;

    let avg_hr = avg_heart_rate(total_hr, total_entry).toFixed(2);
    let avvg_spo2 = avg_spo2(total_spo2, total_entry).toFixed(2);
    let risk_score = calculate_risk_score(avg_heart_rate(total_hr, total_entry), avg_spo2(total_spo2, total_entry)).toFixed(2);

    document.getElementById("show-result").innerHTML = `Average Heart Rate = ${avg_hr}<br>
                                                        Average Oxygen Saturation = ${avvg_spo2} <br>
                                                        Risk Score = ${risk_score}<br><br>`

    if(risk_score <= 10)
        document.getElementById("feedback").innerHTML = `<b>Safe</b><br><br>`
    else if(risk_score >= 11 && risk_score <= 20)
        document.getElementById("feedback").innerHTML = `<b>Warning</b><br><br>`
    else if(risk_score > 20)
        document.getElementById("feedback").innerHTML = `<b>Danger</b><br><br>`
    
    document.getElementById("heart-rate").value = "";
    document.getElementById("spo2").value = "";
});

