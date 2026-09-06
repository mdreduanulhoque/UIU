// @dec Get all contacts
// @route GET /api/contacts
// @access public
const getContacts = (req,res)=>{
    res.json({ message: "Get all contacts"});
};

// @dec Create new contacts
// @route POST /api/contacts
// @access public
const createContact = (req,res)=>{
    res.json({ message: "Create contacts"});
};

// @dec Get contact by ID
// @route GET /api/contacts/:id
// @access public
const getContact = (req,res)=>{
    res.json({ message: `Get the contact for ${req.params.id}`});
};

// @dec Update contact by ID
// @route PUT /api/contacts/:id
// @access public
const updateCotact = (req,res)=>{
    res.json({ message: `Update the contact for ${req.params.id}`});
};

// @dec Delete contact by ID
// @route DELETE /api/contacts/:id
// @access public
const deleteCotact = (req,res)=>{
    res.json({ message: `Delete the contact for ${req.params.id}`});
};


module.exports = {getContacts, createContact, getContact, updateCotact, deleteCotact};