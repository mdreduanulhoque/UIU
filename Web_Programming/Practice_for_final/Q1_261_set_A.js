let study_goal = 20;
let total_study_hours = 0;
let total_study_sessions = 0;
let studied_subjects = "";
let average = 0;
let subject_name = "";
let study_hour = 0;

document.getElementById("add-study").addEventListener("click", function () {

    subject_name = document.getElementById("sub-name").value;
    study_hour = Number(document.getElementById("study-hour").value);

    total_study_hours += study_hour;
    total_study_sessions++;
    studied_subjects += `   ${subject_name}   `;

    average = total_study_hours / total_study_sessions;

    document.getElementById("show-result").innerHTML = `${subject_name} studied for ${study_hour} hours`
});


document.getElementById("show-assesment").addEventListener("click", function () {
    document.getElementById("show-result").innerHTML = `Total study hours = ${total_study_hours}<br>
                                                        Average study hours = ${average} <br>
                                                        Subject(s) studied = ${studied_subjects}<br><br>`

    if(total_study_hours >= 0 && total_study_hours <= 5)
        document.getElementById("feedback").innerHTML = `<b>Start Studying Regularly!</b><br><br>`
    else if(total_study_hours >= 6 && total_study_hours <= 12)
        document.getElementById("feedback").innerHTML = `<b>Good Progress!</b><br><br>`
    else if(total_study_hours >= 13 && total_study_hours <= 19)
        document.getElementById("feedback").innerHTML = `<b>A.most Ready!</b><br><br>`
    else
        document.getElementById("feedback").innerHTML = `<b>Weekly Goal Reached!</b><br><br>`
    
    
    if(total_study_sessions > 7 && total_study_hours < study_goal)
        document.getElementById("extra-feedback").innerHTML = `<b>Increase Your Study Time</b><br><br>`

    document.getElementById("sub-name").value = "";
    document.getElementById("study-hour").va;ue = "";
});